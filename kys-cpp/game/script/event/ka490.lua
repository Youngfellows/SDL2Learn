Talk("王姑娘你好．", 0, 1);
if InTeam(53) == true then goto label0 end;
    exit();
::label0::
    Talk("神仙姊姊．．．神仙姊姊．．．", 138, 1);
    Talk("．．．．．．", 109, 0);
    Talk("忍住，別撲上去", 0, 0);
    if InTeam(53) == true then goto label1 end;
        exit();
::label1::
        ModifyEvent(-2, 0, -2, -2, -1, -1, 491, -1, -1, -1, -2, -2, -2);
exit();
