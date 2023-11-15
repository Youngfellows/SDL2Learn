if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("少了用毒本領高強的何姑娘，行走江湖膽顫心驚，怕被人下毒．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
