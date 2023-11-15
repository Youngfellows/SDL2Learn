if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("老子不干了，我決定啥都不管了，我決定帶著老婆隱居，啥反清復明大業，啥削三藩，給有能力的人操心去吧，後會有期了，兄弟．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
