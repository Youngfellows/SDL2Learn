Talk("阿彌陀佛，施主請留步．", 70, 0);
DarkScence();
ModifyEvent(-2, 3, 1, 1, 515, -1, -1, 5372, 5372, 5372, -2, -2, -2);
ModifyEvent(-2, 4, 1, 1, -1, -1, -1, 5420, 5420, 5420, -2, -2, -2);
ModifyEvent(-2, 5, 1, 1, -1, -1, -1, 5420, 5420, 5420, -2, -2, -2);
ModifyEvent(-2, 6, 1, 1, -1, -1, -1, 5420, 5420, 5420, -2, -2, -2);
LightScence();
Talk("怎麼，方丈後悔了．", 139, 1);
Talk("老衲想通了，既造業因，便有業果．自己的名聲固然重要，但是我虧欠喬峰一家人實在太多了，我不能再讓你去害他．", 70, 0);
Talk("方丈這是做什麼，今天我去揭發喬峰，是為武林除害．", 139, 1);
Talk("是嗎？依老衲看，是為了你大燕復國的計畫吧．其實我早就該想到了，當初就是你父親慕容博施主，假傳音訊，說是契丹武士要大舉侵犯少林奪取武學典籍，才會釀成大錯．這一切，都是你父親要挑起漢遼武人相斗，使你大燕從中取利．", 70, 0);
Talk("．．．．．", 139, 1);
Talk("快將信件留下．", 70, 0);
Talk("方丈不怕我將你的事也揭露出來．", 139, 1);
Talk("我個人事小，中原武林的和諧才重要，我不能讓你利用此信，引起武林的大風暴．", 70, 0);
Talk("好，你別怪我．這事傳出去後，看你少林寺的臉往那里擺．一個堂堂的少林方丈和女人亂來，還生下了一名私生子．．．．．", 139, 1);
Talk("有這等事？", 0, 1);
Talk("阿彌陀佛！老衲是犯了佛門大戒，待將你們拿下，取回信件後，老衲自會自我懲處．", 70, 0);
Talk("復兒，這里有我。你們先走。", 67, 1);
Talk("爹，是您老人家？好，兄弟我們先走。", 139, 0);
Talk("有我在，你們一個也別想走！", 60, 1);
Talk("又是你，閣下究竟是誰？", 67, 0);
Talk("去地獄問閻王吧!", 60, 1);
Talk("誰去見閻王還不知道呢?", 67, 0);
Talk("慕容施主，現在我強你弱。你還想一戰嗎？", 70, 1);
Talk("哦，那再加上我鳩摩智呢？", 140, 0);
Talk("明王也要插手嗎？", 70, 1);
Talk("今日都到齊了，是該做個了斷了。", 56, 0);
Talk("二娘！你也……", 70, 1);
Talk("什么都先別說了，殺了他們再說。", 56, 0);
Talk("看來免不了一戰了．", 139, 1);
if TryBattle(81) == true then goto label0 end;
    Dead();
    exit();
::label0::
    ModifyEvent(-2, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 3, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 4, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 5, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 6, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 12, -2, -2, 578, -1, -1, -2, -2, -2, -2, -2, -2);
    ModifyEvent(51, 14, -2, -2, 527, 531, -1, -2, -2, -2, -2, -2, -2);
    LightScence();
    Talk("好亂啊！我真的做對了嗎？", 0, 1);
    AddFame(8);
exit();
