Talk("少了用毒本領高強的何姑娘，行走江湖膽顫心驚，怕被人下毒．", 0, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 184, 0);
        exit();
::label1::
        Talk("愛裝傻，你這小子內力深厚，連我都毒死不了你，何況是其他下三濫．", 184, 0);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Join(66);
exit();
