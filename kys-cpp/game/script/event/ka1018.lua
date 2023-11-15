if InTeam(58) == true then goto label0 end;
    Talk("這里看起來好像埋著啥東西?上面寫著劍塚?", 0, 0);
    Talk("劍塚，我看成賤種", 0, 0);
    exit();
exit();
::label0::
    if HaveItemBool(114) == true then goto label1 end;
        Talk("這里可能是獨孤前輩埋劍之地", 118, 0);
        Talk("三十歲前，使之橫行天下，誤傷義士不祥，封劍於此，這把寶劍不知傷了哪位前輩，能讓獨孤前輩如此自責", 118, 5);
        AddItem(114, 1);
        Talk("這把劍猛", 0, 0);
        exit();
exit();
::label1::
        Talk("還有一行字，重劍無鋒，大巧不工，四十歲前始之橫行天下，這把應該楊兄的那把又黑又重玄鐵劍吧!", 0, 0);
        Talk("四十歲後，不滯於物，草木竹石均可為劍，自此精修，達到無劍勝有劍之境，虎濫程度可以跟七龍珠比", 0, 0);
        exit();
exit();
