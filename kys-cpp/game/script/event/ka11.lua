Talk("有什麼要我幫忙的，盡管說出來．", 1, 0);
if AskJoin () == true then goto label0 end;
    exit();
::label0::
    Talk("胡大哥肯隨我闖蕩江湖否？", 0, 1);
    if TeamIsFull() == false then goto label1 end;
        Talk("你的隊伍已滿，我無法加入．", 1, 0);
        exit();
::label1::
        Talk("好．我就隨你一走．", 1, 0);
        Talk("胡大哥肯隨我闖蕩江湖幫這個忙，那再好也不過了．", 0, 1);
        DarkScence();
        ModifyEvent(-2, -2, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2);
        LightScence();
        Join(1);
        AddMorality(1);
exit();
