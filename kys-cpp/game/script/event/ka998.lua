Talk("上面寫著：愛女凌霜華之墓，知府凌退思立．", 177, 1);
Talk("奇怪，怎麼這墓碑上有一個似曾相似的味道，啊!丁典兄弟快離開墓碑，上面有金波旬花的毒．", 0, 0);
Talk("啊，我道是誰，原來是丁大俠。小女不幸逝世，有勞吊唁，存歿同感。小女去世已五天了，大夫也說不上是什么病癥，只說是郁積難消。", 176, 0);
DarkScence();
ModifyEvent(-2, 12, 0, -2, -1, -1, -1, 8336, 8336, 8336, -2, -2, -2);
LightScence();
Talk("丁大俠，你可忒也固執了，倘若早早說了出來，小女固然不會給你害死，我和你更成了翁婿，那是何等的美事。", 176, 0);
Talk("你說霜華是我害死的？不是你害死她的？", 177, 0);
Talk("事已如此，還說什么？霜華啊，霜華，你九泉之下，定是怪爸爸不體諒你了。", 176, 0);
Talk("倘若我今日殺了你，霜華在天之靈定然恨我。凌退思，瞧在你女兒的份上，你折磨了我這七年，咱們一筆勾銷。今后你再惹上我，可休怪姓丁的無情。我現在就走!", 177, 0);
Talk("有事要找本府嗎?", 176, 0);
Talk("大哥，我只是來跟你拜個碼頭，沒必要這要群毆我吧，干 要不是中了那個金波旬花，沒了內力，我何必低聲下氣．", 177, 0);
Talk("丁典兄弟，你身中劇毒，這里就交給我來，你別妄動內力．", 0, 0);
if TryBattle(224) == true then goto label0 end;
    Dead();
    exit();
::label0::
    OldSetScencePosition(45, 39);
    ModifyEvent(-2, 3, 0, -2, -2, -2, 1205, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 4, 0, -2, -2, -2, 1205, -2, -2, -2, -2, -2, -2);
    ModifyEvent(-2, 5, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 12, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    ModifyEvent(-2, 21, -2, -2, -1, -1, -1, 5408, 5408, 5408, -2, -2, -2);
    LightScence();
    Talk("到這里追兵應該就不會追來，丁典兄弟你在這待著，我去找凌退思拿解藥．", 0, 0);
    Talk("不用了，‘金波旬花’的劇毒，天下無藥可解，挨得一刻是一刻，看來我是撐不久了，我死後希望能霜華合葬在一起，再會了兄弟．．．．．．．．．．．．", 177, 0);
    DarkScence();
    ModifyEvent(-2, 21, -2, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    LightScence();
    Talk("狄云知道丁典掛了一定很傷心，丁典的屍體就交給他處理，那個狄云跑到哪了?", 0, 0);
exit();