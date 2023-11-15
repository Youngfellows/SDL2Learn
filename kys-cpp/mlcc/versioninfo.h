#pragma once
#include <string>
#include <Windows.h>
#include "fmt1.h"

#pragma comment(lib, "version.lib")

enum InfoType
{
    InfoType_Version,
    InfoType_FileDescription,
};

inline std::string get_version(const std::string& filename, InfoType it)
{
    DWORD verHandle = 0;
    UINT size = 0;
    LPBYTE lpBuffer = NULL;
    DWORD verSize = GetFileVersionInfoSizeA(filename.c_str(), &verHandle);

    if (verSize != NULL)
    {
        std::string verData;
        verData.resize(verSize);
        if (GetFileVersionInfoA(filename.c_str(), verHandle, verSize, (LPVOID)verData.data()))
        {
            if (it == InfoType_Version && VerQueryValueA(verData.data(), "\\", (VOID FAR * FAR*)&lpBuffer, &size))
            {
                if (size)
                {
                    VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
                    if (verInfo->dwSignature == 0xfeef04bd)
                    {
                        // Doesn't matter if you are on 32 bit or 64 bit,
                        // DWORD is always 32 bits, so first two revision numbers
                        // come from dwFileVersionMS, last two come from dwFileVersionLS
                        return fmt1::format("{}.{}.{}.{}",
                            (verInfo->dwFileVersionMS >> 16) & 0xffff,
                            (verInfo->dwFileVersionMS >> 0) & 0xffff,
                            (verInfo->dwFileVersionLS >> 16) & 0xffff,
                            (verInfo->dwFileVersionLS >> 0) & 0xffff);
                    }
                }
            }
            if (it == InfoType_FileDescription && VerQueryValue(verData.data(), TEXT("\\VarFileInfo\\Translation"), (VOID FAR * FAR*)&lpBuffer, &size))
            {
                if (size)
                {
                    // Read the list of languages and code pages.
                    struct LANGANDCODEPAGE
                    {
                        WORD wLanguage;
                        WORD wCodePage;
                    }* lpTranslate;

                    lpTranslate = (struct LANGANDCODEPAGE*)lpBuffer;
                    // Read the file description for each language and code page.
                    for (UINT i = 0; i < (size / sizeof(struct LANGANDCODEPAGE)); i++)
                    {
                        char SubBlock[50];
                        snprintf(SubBlock, 50, "\\StringFileInfo\\%04x%04x\\FileDescription", lpTranslate[i].wLanguage, lpTranslate[i].wCodePage);
                        if (VerQueryValueA(verData.data(), SubBlock, (VOID FAR * FAR*)&lpBuffer, &size))
                        {
                            return (const char*)lpBuffer;
                        }
                    }
                }
            }
        }
    }
    return "";
}
