if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("小寶前幾天才帶媳婦來找我，還帶個白白胖胖的孫子，沒想老娘升級做阿嬤了．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
