if isUsingItem(128) == true then goto label0 end;
    exit();
::label0::
    Talk("這．．這是我逍遙派掌門之信物，怎會在閣下手中．", 45, 0);
    Talk("沒想到你居然也混逍遙派，你師祖已將逍遙派掌門傳給虛竹了．．．事情是這樣的．．．你師父跟我們說，如果有需要醫術高明的人加入的話，可以來這邊找你．", 0, 1);
    Talk("既然如此，那我加入你吧．", 45, 0);
    ModifyEvent(-2, -2, -2, -2, 556, -1, -1, -2, -2, -2, -2, -2, -2);
exit();
