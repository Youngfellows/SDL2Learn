Talk("媽的，只好摸黑作戰了。", 0, 0);
Talk("啊~~", 153, 4);
Talk("還是圣姑聰明，猜到這些盲人用這句話當做自己人的暗號，不然今天很可能死在這。", 35, 0);
Talk("終於出來了，剛才真驚險，差點喪命．", 19, 5);
Talk("沖哥，從前你師父罰你在這里思過，就住在這個石洞里麼？", 153, 0);
Talk("正是。風太師叔便住在左近，不知他老人家身幾是否安健。我一直好生想念。他本來說過，決計不見華山派之人，但我早就不是華山派的了。", 19, 5);
Talk("小賊，你得意洋洋的從洞中出來，可不知即將大禍臨頭罷？任大小姐，你要我先殺他呢，還是先殺你？", 153, 0);
Talk("你不就是想要我身上三尸腦神丹’的解藥，可我這只有三顆。", 0, 0);
Talk("好，那麼咱們做一個交易。你將制解藥之法跟我說了，我便饒你們不死。", 19, 5);
if HaveItemBool(43) == false then goto label0 end;
    Talk("小女子雖然年輕識淺，卻也知道君子劍岳先生的為人。閣下如果言而有信，也不會叫作君子劍了。", 0, 0);
    Talk("岳先生可把我們看成甕中鱉了?岳先生有這個本錢嗎?", 19, 5);
::label0::
    Talk("如今我辟邪劍法大成，天下已無敵手，誰能威脅的了我。", 0, 0);
    Talk("不知岳先生有沒有聽過，九陽神功驚俗世，君臨天下易筋經?", 19, 5);
    AddAttack(19, 100);
    AddMaxHP(19, 800);
    AddMaxMP(19, 500);
    AddSpeed(19, 30);
    if TryBattle(260) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("有又如何?", 35, 0);
        Talk("那你就準備被我轟爆吧!", 19, 5);
        Talk("夸口的小子，讓你嘗嘗我十層功力的避邪劍法。", 0, 0);
        Talk("兄弟手下留情!畢竟岳先生和我曾有師徒之情，你走吧!", 19, 5);
        DarkScence();
        ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(29, 0, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(29, 1, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(57, 0, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(57, 1, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(58, 9, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(58, 10, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(58, 11, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(27, 53, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        ModifyEvent(27, 54, 1, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
        LightScence();
        Talk("這不可能，我廢盡心思得到的辟邪劍法，我為了天下無敵還揮劍自宮 沒想到，不可能。", 0, 0);
        Talk("拍謝，是我太強了，難為你自宮卻還不是天下第一。", 35, 4);
exit();
