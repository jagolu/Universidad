package NapakalakiGame;

import java.util.ArrayList;
import java.util.ArrayList;
import GUI.NapakalakiView;
import GUI.Dice;
import GUI.PlayerNamesCapture;
import GUI.BadConsequenceView;
import GUI.MonsterView;
import GUI.Playerview;
/**
 *
 * @author javigomez
 */
public class Main {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Napakalaki napakalakiModel = Napakalaki.getInstance();
        NapakalakiView napakalakiView = new NapakalakiView();
        Dice.createInstance(napakalakiView);
        PlayerNamesCapture namesCapture = new PlayerNamesCapture(napakalakiView, true);
        ArrayList<String> names = namesCapture.getNames();
        napakalakiModel.initGame(names);
         napakalakiView.setNapakalaki(napakalakiModel);
         
        napakalakiView.setVisible(true); 
    }
}
