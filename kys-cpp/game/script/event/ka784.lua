if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("嗚，鄭公子本來答應我一回臺灣就要娶我，可是到臺灣後，鄭公子就把我冷落在一邊，鄭公子的母親也不喜歡我，時常把我叫去，羞辱我一翻．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
