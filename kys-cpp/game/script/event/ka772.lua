if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("夭壽死人骨，小寶，我告訴你多少次，我們雖窮，但也不可以偷別人的錢，你看看，這麼多銀票銀兩要是不見了，一定會很緊張的到處找，我幫你收起來還給客人．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
