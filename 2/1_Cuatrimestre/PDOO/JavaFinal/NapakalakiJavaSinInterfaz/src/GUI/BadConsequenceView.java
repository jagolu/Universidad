/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GUI;

import NapakalakiGame.BadConsequence;
import javax.swing.Icon;
import javax.swing.ImageIcon;

/**
 *
 * @author anonymous
 */
public class BadConsequenceView extends javax.swing.JPanel  {
private BadConsequence bd;
   private Object imagen;
    /**
     * Creates new form BadConsequenceView
     */
    public BadConsequenceView() {
        initComponents();
    }
    public void setBadConsequence(BadConsequence bd2){
        bd=bd2;
        text.setText(bd.getText());
        repaint();
    }
    /**
     * Creates new form BadConsequenceView
     */
    

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        text = new javax.swing.JLabel();

        setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        text.setFont(new java.awt.Font("Dialog", 1, 10)); // NOI18N
        text.setText("jLabel2");
        add(text, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 540, 50));
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel text;
    // End of variables declaration//GEN-END:variables
}