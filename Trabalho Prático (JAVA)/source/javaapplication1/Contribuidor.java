/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.util.Objects;

/**
 *
 * @author lois__000
 */
public class Contribuidor {
    private long idcontribuidor;
    private String nomecontribuidor;
    private int contribuicoes;
    
    public Contribuidor(){
        this.idcontribuidor=0;
        this.nomecontribuidor=new String();
        this.contribuicoes=0;
    }
    public Contribuidor(long idcontribuidor, String nomecontribuidor,int contribuicoes ){
        this.idcontribuidor=idcontribuidor;
        this.nomecontribuidor=nomecontribuidor;
        this.contribuicoes=contribuicoes;
    }
    public Contribuidor(Contribuidor c){
        this.idcontribuidor=c.getIdcontribuidor();
        this.nomecontribuidor=c.getNomecontribuidor();
        this.contribuicoes=c.getContribuicoes();
    }

    public long getIdcontribuidor() {
        return idcontribuidor;
    }

    public void setIdcontribuidor(long idcontribuidor) {
        this.idcontribuidor = idcontribuidor;
    }

    public String getNomecontribuidor() {
        return nomecontribuidor;
    }

    public void setNomecontribuidor(String nomecontribuidor) {
        this.nomecontribuidor = nomecontribuidor;
    }

    public int getContribuicoes() {
        return contribuicoes;
    }

    public void setContribuicoes(int contribuicoes) {
        this.contribuicoes = contribuicoes;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Contribuidor other = (Contribuidor) obj;
        if (this.idcontribuidor != other.idcontribuidor) {
            return false;
        }
        if (this.contribuicoes != other.contribuicoes) {
            return false;
        }
        if (!Objects.equals(this.nomecontribuidor, other.nomecontribuidor)) {
            return false;
        }
        return true;
    }
    
    @Override
    public String toString() {
        return "Contribuidor{" + "idcontribuidor=" + idcontribuidor + ", nomecontribuidor=" + nomecontribuidor + ", contribuicoes=" + contribuicoes + '}';
    }
    
    public Contribuidor clone(){
        return new Contribuidor(this);
    }

   
}
