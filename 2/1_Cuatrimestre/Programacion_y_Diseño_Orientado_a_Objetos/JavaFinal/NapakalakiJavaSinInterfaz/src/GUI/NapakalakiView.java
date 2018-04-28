/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;
import NapakalakiGame.Napakalaki;
import NapakalakiGame.CombatResult;
/**
 *
 * @author Javi
 */
public class NapakalakiView extends javax.swing.JFrame {
    Napakalaki napakalakiModel;
    
    public NapakalakiView() {
        initComponents();
        NextTurn.setEnabled(false);
        monsterView1.setVisible(false);
        Combat.setEnabled(false);
    }
    
    /**
     *
     * @param n
     */
    public void setNapakalaki(Napakalaki n){
        napakalakiModel=n;
        playerview1.setPlayer(napakalakiModel.getCurrentPlayer());
        monsterView1.setMonster(napakalakiModel.getCurrentMonster());
        playerview1.setNapakalakiModel(napakalakiModel);
    }
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        playerview1 = new GUI.Playerview();
        monsterView1 = new GUI.MonsterView();
        meetTheMonster = new javax.swing.JButton();
        Combat = new javax.swing.JButton();
        NextTurn = new javax.swing.JButton();
        resultados = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        meetTheMonster.setText("Meet the monster");
        meetTheMonster.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                meetTheMonsterActionPerformed(evt);
            }
        });

        Combat.setText("Combat");
        Combat.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                CombatActionPerformed(evt);
            }
        });

        NextTurn.setText("Next turn");
        NextTurn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                NextTurnActionPerformed(evt);
            }
        });

        resultados.setText(" ");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(playerview1, javax.swing.GroupLayout.PREFERRED_SIZE, 610, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(70, 70, 70)
                        .addComponent(resultados, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(monsterView1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap(75, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(meetTheMonster)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(Combat))
                            .addComponent(NextTurn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(98, 98, 98))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(monsterView1, javax.swing.GroupLayout.PREFERRED_SIZE, 236, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(50, 50, 50)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(meetTheMonster)
                    .addComponent(Combat))
                .addGap(18, 18, 18)
                .addComponent(NextTurn, javax.swing.GroupLayout.PREFERRED_SIZE, 121, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(55, 55, 55)
                .addComponent(resultados)
                .addContainerGap(101, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addComponent(playerview1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void CombatActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_CombatActionPerformed
        CombatResult c=napakalakiModel.developCombat();
        if(c==CombatResult.WINGAME) {
            resultados.setText("Has ganado el juego");
            playerview1.TodosBotonesFalse();                   
            Combat.setEnabled(false);
            NextTurn.setEnabled(false);
            meetTheMonster.setEnabled(false);
            playerview1.setPlayer(napakalakiModel.getCurrentPlayer());
        }
        else{
            if(c==CombatResult.WIN) resultados.setText("Has ganado el combate");
            if(c==CombatResult.LOSE) resultados.setText("Has perdido el combate");
            if(c ==CombatResult.LOSEANDCONVERT)resultados.setText("Has perdido y te transformas");
            monsterView1.setVisible(true);
            NextTurn.setEnabled(true);
            meetTheMonster.setEnabled(false);
            Combat.setEnabled(false);
            playerview1.DiscardsToTrue();
            playerview1.setPlayer(napakalakiModel.getCurrentPlayer()); 
        }
        setNapakalaki(napakalakiModel);
    }//GEN-LAST:event_CombatActionPerformed

    private void NextTurnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_NextTurnActionPerformed
        boolean a=napakalakiModel.nextTurn();
        if(a){
            monsterView1.setVisible(false);
            playerview1.AllTrue();
            resultados.setText(" ");
            Combat.setEnabled(false);
            meetTheMonster.setEnabled(true);
            NextTurn.setEnabled(false);
            playerview1.SetStealTreasureEmpty();
        }
        else{
            playerview1.DiscardsToTrue();
            Combat.setEnabled(false);
            resultados.setText("Aun no puedes pasar turno");
        }
        setNapakalaki(napakalakiModel);
    }//GEN-LAST:event_NextTurnActionPerformed

    private void meetTheMonsterActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_meetTheMonsterActionPerformed
        monsterView1.setVisible(true);
        Combat.setEnabled(true);
        playerview1.TodosBotonesFalse();
        meetTheMonster.setEnabled(false);
    }//GEN-LAST:event_meetTheMonsterActionPerformed



    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Combat;
    private javax.swing.JButton NextTurn;
    private javax.swing.JButton meetTheMonster;
    private GUI.MonsterView monsterView1;
    private GUI.Playerview playerview1;
    private javax.swing.JLabel resultados;
    // End of variables declaration//GEN-END:variables
}
