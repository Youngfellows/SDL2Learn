if isUsingItem(124) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(124, -1);
    Talk("師父，我看這蜜蜂很難馴養哦！", 0, 1);
    Talk("沒什麼的，再過一陣子我就會讓這百花谷中到處都是蜜蜂飛舞．", 64, 0);
    Talk("我這有罐玉蜂漿，你拿去試看看，會不會比較好用．", 0, 1);
    ModifyEvent(-2, -2, -2, -2, -2, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 2, -2, -2, -1, -1, 408, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 3, -2, -2, -1, -1, 408, -2, -2, -2, -2, -2, -2);
exit();
