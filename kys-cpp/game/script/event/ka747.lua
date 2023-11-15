if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("什么下作上作？殺人就是殺人，用刀子是殺人，用拳頭是殺人，下毒用藥，還不一樣是殺人？江湖上的英雄好漢瞧不起？哼，誰要他們瞧得起了？像那些武林中人還不是殺了幾千幾百人，他不用毒藥，難道就該瞧得起他了", 161, 0);
    Add3EventNum(-2, 0, 0, 1, -1)
exit();
