if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("干，臺灣高雄鳳山凱名認不認識拉，我給他罩的，怕了吧．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
