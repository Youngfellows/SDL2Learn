ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
if CheckEventID(2, -1) == true then goto label0 end;
    ModifyEvent(-2, 2, -2, -2, 862, -1, -1, -2, -2, -2, -2, -2, -2);
::label0::
    if CheckEventID(3, -1) == true then goto label1 end;
        ModifyEvent(-2, 3, -2, -2, 863, -1, -1, -2, -2, -2, -2, -2, -2);
::label1::
        if CheckEventID(4, -1) == true then goto label2 end;
            ModifyEvent(-2, 4, -2, -2, 864, -1, -1, -2, -2, -2, -2, -2, -2);
::label2::
            if CheckEventID(5, -1) == true then goto label3 end;
                ModifyEvent(-2, 5, -2, -2, 865, -1, -1, -2, -2, -2, -2, -2, -2);
::label3::
exit();
