Talk("這不是阿珂嗎?阿珂你放心，我不會再強迫你當我老婆，管你是喜歡鄭克爽還是足爽，我都不管了，咦，你怎麼哭了．", 162, 5);
Talk("嗚，鄭公子本來答應我一回臺灣就要娶我，可是到臺灣後，鄭公子就把我冷落在一邊，鄭公子的母親也不喜歡我，時常把我叫去，羞辱我一翻．", 187, 0);
Talk("真有此事，他奶奶的我現在就去找那鄭克爽，替你出口氣．", 162, 5);
Talk("小寶．．．你能帶我走嗎?", 187, 0);
Talk("什麼!你說要跟我走，真的嗎?我說的是那種我帶走你，然後做我老婆那種．", 162, 5);
Talk("雖然我一開始很討厭你，但我知道，我如果跟了你，你一定會對我很好很好．", 187, 0);
Talk("你終於想通了，你的選擇是對的，跟著我保證你一輩子都快樂，兄弟，我要跟我老婆去消遙了，跟你在一起的時間過的很快樂，掰．", 162, 5);
Talk("那天地會跟康熙那怎麼交代?", 0, 1);
Talk("老子不干了，我決定啥都不管了，我決定帶著老婆隱居，啥反清復明大業，啥削三藩，給有能力的人操心去吧，後會有期了，兄弟．", 162, 5);
DarkScence();
ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
LightScence();
if InTeam(49) == false then goto label0 end;
    Talk("這個一直想嫁入豪門的腦殘女終於想開了，最後跟著一心一意待他好的好人．", 49, 1);
    Talk("中肯!靠北，你什麼時候發言變的那麼中肯．", 0, 5);
::label0::
    ModifyEvent(59, 10, -2, -2, 714, -2, -2, -2, -2, -2, -2, -2, -2);
exit();