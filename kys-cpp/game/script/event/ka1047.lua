Talk("干，這個床還真冰，難道這就是傳說中的寒玉床．", 0, 0);
if AskRest() == true then goto  label0 end;
    Talk("都快冷死了還躺下去睡，我瘋了嗎?", 0, 0);
    exit();
::label0::
    Rest();
    LightScence();
    AddMaxHP(0, 1);
    AddMaxMP(0, 1);
exit();
