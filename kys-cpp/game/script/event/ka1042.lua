Talk("小子剛打完一架是不是？休息一下在上，別累壞自己的身子．", 12, 0);
Talk("很可惜，剛剛那個垃圾讓我連熱身運動都沒做到．", 0, 0);
Talk("找死!", 142, 0);
if TryBattle(194) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 3, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 4, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    Talk("干你媽的，突然偷襲我，夠機掰。", 0, 0);
exit();
