WalkFromTo(28, 27, 28, 21);
Talk("哀，你這個人還真不上道啊!九一!", 0, 5);
DarkScence();
LightScence();
Talk("這個人還真是一個雜碎．", 0, 5);
Talk("下次吧。", 197, 0);
Talk("他媽的，走在沙漠中快被渴死了，咦，還瞞多人在這休息的嘛，老頭來點水喝喝。", 200, 1);
Talk("你也差不多．．．．", 0, 5);
Talk("．．．．．．", 200, 1);
Talk("呵呵，我們還真有緣啊!又見面了，別緊張，我不會對你怎麼樣，畢竟我們是客人，怎麼可以在主人家動手呢。", 195, 0);
Talk("啊!你是那個漢人盜賊。", 203, 4);
Talk("在下 在下還有一些事要辦 ，告辭", 197, 0);
Talk("<剛才第二個進來的人，手上拿的是媽媽的雙劍不會錯，這人正是當年指揮人眾、追殺他父親的三個首領之一，沒想到今天讓我遇到這個賊人。>", 203, 4);
Talk("老伯伯，我可不可以向你打聽一個人。", 195, 0);
Talk("誰啊?", 203, 4);
Talk("那是我小時候常跟她在一起玩兒的，一個漢人小姑娘……", 197, 0);
Talk("<他還記得我，蘇普還記得的我。>", 195, 0);
Talk("她叫做阿秀，後來隔了八九年，一直沒在見到她。她是跟一位漢人老公公住在一起的。那一定就是你了？", 203, 4);
Talk("她不……她不在了……", 200, 5);
Talk("你說的那個漢人姑娘，我倒也識得。她早死了好幾年啦！", 203, 4);
Talk("啊，她死了，怎??會死的？我小時候常和她一同去牧羊，她唱了很多歌給我聽，還說了很多故事。好幾年不見，想不到她……她竟死了。她還說她爹媽都給惡人害死了，孤苦伶仃的到這地方來，沒想到……", 200, 5);
Talk("等等，你說是一個漢人小姑娘？她父母被害，并且騎著一匹白馬，獨個兒到這里來？", 197, 0);
Talk("是啊，那你也見過她了。", 200, 5);
Talk("老頭，她死在你這兒的？她留下來的東西呢？你都好好放著??？", 197, 0);
Talk("這關你甚??事？", 200, 5);
Talk("我姓陳，名達海，江湖上外號叫做青蟒劍，那小女孩於我有極大的關系，所以那女孩的遺物交出來給我保管。", 195, 0);
if TryBattle(262) == true then goto label0 end;
::label0::
    LightScence();
    Talk("我沒聽見過你的名字，你休息好了就快走，別呆在這。", 200, 5);
    Talk("沒想到老頭子是個高手，他媽的，只好先逃了。", 0, 1);
    Talk("嘿，心虛了吧!交出高昌迷宮地圖!", 195, 0);
    Talk("<想跟爺爺動手，這陳達海走楣運了。>", 197, 0);
    Talk("爺爺，好久沒看你動手了，沒想到你還是這麼厲害。", 203, 4);
    Talk("蘇普啊!他就是你剛才想要找的阿秀，剛才說阿秀死掉，是為了騙那個壞蛋。", 195, 0);
    Talk("<大漠茫茫，居然出了這樣一個高手?>", 203, 4);
    Talk("阿秀!你真的是阿秀!你沒死真是太好了，只可惜阿曼不在，不然看到你一定很高興。", 195, 0);
    Talk("阿曼怎麼了?", 197, 0);
    Talk("我們塔塔兒人和蒙古乃世仇，前幾天鐵木真大舉入侵我族，盡屠車輪一般高的男人，雖然我盡全力逃了出來，可是阿曼，阿曼也被鐵木真部下們擄去了。", 0, 1);
    if InTeam(49) == false then goto label1 end;
        Talk("少多管閑事，這麻煩的事還是少碰為妙，惹到蒙古，我們就別想在大漠平平安安的住下去。", 49, 5);
        Talk("老頭不方便的話，其實我可以幫助蘇兄弟救出阿曼姑娘。", 0, 4);
::label1::
        Talk("阿普你放心，我會幫忙把阿曼就出來，爺爺你也會幫忙阿普吧!", 195, 4);
        Talk("你說的是真的嗎?", 0, 1);
        Talk("你是好人!!!<指>", 195, 4);
        Talk("干!我為什麼要被你發卡。", 0, 1);
        if InTeam(49) == false then goto label2 end;
            Talk("剛剛你不是說你老母被陳達海殺了。", 49, 5);
::label2::
            Talk("不過有個條件，事成後可不可以把高昌地圖給我。", 195, 0);
            Talk("哼，沒想到你也是跟陳達海一樣，一丘之駱。", 0, 1);
            Talk("誤會啊!姑娘，你慢慢聽我道來，小人本住在蘇州的城邊，家中有屋又有田，生活樂無邊。 誰知那陳達海，他蠻橫不留情，勾結官府目無天，殺我老母奪我田。 我爺爺跟他來翻臉，慘被他一棍來打扁； 我奶奶罵他欺善民，反被他強奸了一百遍，一百遍； 他還將我兩父子，逐出了家園，流落到江邊。 我為求養老爹，只有獨自行乞在廟前， 誰知那陳達海，他實在太陰險，知道此情形，竟派人來暗算， 將我父子狂毆在市前，小人身壯健，殘命得留存， 可憐老父他魂歸天，此恨更難填！ 為了手刃仇人意志堅， 從此每天練功到半夜，我銘記此仇不共戴天！", 195, 0);
            Talk("這麼說來你跟陳達海有很大的仇恨?", 0, 1);
            Talk("沒錯，我除了還要破壞陳達海的好事外，聽說高昌迷宮內有千年人參，我想起遠在他鄉的母親，我想我也該帶點千年人蔘給他補補身子，以盡孝道，因此特地請求姑娘借地圖一用", 195, 0);
            ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
            ModifyEvent(17, 0, -2, 0, 740, -1, -1, -2, -2, -2, -2, -2, -2);
exit();
