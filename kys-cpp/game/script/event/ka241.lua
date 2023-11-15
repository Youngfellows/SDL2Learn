if isUsingItem(126) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(126, -1);
    ModifyEvent(-2, -2, -2, -2, 240, 242, -1, -2, -2, -2, -2, -2, -2);
    Talk("嗯！好一壇梨花酒！曾聞白樂天杭州喜望詩云：”紅袖織綾夸柿葉，  青旗沽酒趁梨花”．這壇梨花酒酒味是極好，只可惜少了股芳冽之氣，若能以翡翠杯盛之而飲，那更是醇美無比．", 35, 0);
exit();
