if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("好啦好啦<媽的，居然不相信我發財了>．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
