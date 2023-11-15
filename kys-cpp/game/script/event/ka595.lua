Talk("郡主有令，擅闖者死！", 91, 0);
Talk("擋我者死．", 0, 1);
if TryBattle(91) == true then goto label0 end;
    Dead();
    exit();
::label0::
    LightScence();
    if HaveItemBool(44) == true then goto label1 end;
        Talk("大力金剛指！你好像不是少林和尚？", 0, 0);
        Talk("少林派的金剛指算什么。", 96, 1);
        Talk("那你又是哪們哪派的呢？", 0, 0);
        Talk("告訴你也無妨，我是金剛門的弟子。", 96, 1);
        Talk("原來是西域的高手？", 0, 0);
        ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        AddFame(1);
exit();
::label1::
        Talk("大力金剛指！空性大師是你殺的？", 0, 0);
        Talk("不錯！空性那個老禿驢和我對打，讓我把他的腦袋扭掉了。", 96, 1);
        Talk("明年今日就是你的死祭。", 0, 0);
        Talk("要殺就動手吧，你到里頭自會有人替我報仇。", 96, 1);
        Talk("看門的武功就著麼高，難道里面還有高手？", 0, 0);
        ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        AddFame(1);
exit();
