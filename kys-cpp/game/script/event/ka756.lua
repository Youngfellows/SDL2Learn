if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("袁承志就是我師父，看你這麼興奮的樣子，應該是聽說了十四天書中的碧血劍就在我師父手中，想要找我師父拿走此書吧，勃泥島不是我們買的地，想來就來要跟就跟吧，如果你是啥心術不正的人，師父自然會教訓你．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
