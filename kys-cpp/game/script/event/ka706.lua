Talk("何姑娘，你也認為島上很悶吧，要不要離開這個小島跟我一起闖蕩江湖．", 0, 0);
if InTeam(54) == false then goto label0 end;
    Talk("既然師父都跟你走了，我當然沒問題．", 184, 0);
    DarkScence();
    ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    Join(66);
    exit();
::label0::
    Talk("我也很想，但是沒有師父的允許我是不會離開渤泥島的", 184, 0);
    exit();
exit();
