/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
import java.util.*;
/**
 *
 * @author lois__000
 */
public class Artigo {
    private int nrevisoes;
    private int idtitulo;
    private Map<Integer,Set<Revisao>> revisoes;
    
     public Artigo() {
         this.nrevisoes=0;
         this.idtitulo=0;
         this.revisoes= new HashMap<>();
    }
  
    public Artigo(int nrevisoes,int idtitulo, Map<Integer,Set<Revisao>>revisoes) {
        this.nrevisoes = nrevisoes;
        this.idtitulo= idtitulo;
        this.revisoes = new HashMap<>();
        for(Integer i : revisoes.keySet()){
            Set<Revisao> aux= new TreeSet<>();
            for(Revisao r: revisoes.get(i)){
                aux.add(r.clone());
            }
            this.revisoes.put(i, aux);
        }
    }
    
     public Artigo(Artigo a) {
         this.nrevisoes=a.getNrevisoes();
         this.revisoes=a.getRevisoes();
         this.idtitulo=a.getIdtitulo();
    }
    
    

    public int getNrevisoes() {
        return this.nrevisoes;
    }

    public void setNrevisoes(int nrevisoes) {
        this.nrevisoes = nrevisoes;
    }
    
    public int getIdtitulo(){
        return this.idtitulo;
    }
    
    public void setIdtitulo(int idtitulo){
        this.idtitulo=idtitulo;
    }
    
    public Map<Integer, Set<Revisao>> getRevisoes() {
        Map<Integer, Set<Revisao>> res  = new HashMap<>();
        for(Integer i : revisoes.keySet()){
            Set<Revisao> aux= new TreeSet<>();
            for(Revisao r: revisoes.get(i)){
                aux.add(r.clone());
            }
            res.put(i, aux);
        }
        return res;
    }

    public void setRevisoes(Map<Integer, Set<Revisao>> revisoes) {
        this.revisoes.clear();
        for(Integer i : revisoes.keySet()){
            Set<Revisao> aux= new TreeSet<>();
            for(Revisao r: revisoes.get(i)){
                aux.add(r.clone());
            }
            this.revisoes.put(i, aux);
        }
    }
    
    
    
        
        

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 97 * hash + this.nrevisoes;
        hash = 97 * hash + this.idtitulo;
        hash = 97 * hash + Objects.hashCode(this.revisoes);
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
        final Artigo other = (Artigo) obj;
        if (this.nrevisoes != other.nrevisoes) {
            return false;
        }
        if (this.idtitulo != other.idtitulo) {
            return false;
        }
        if (!Objects.equals(this.revisoes, other.revisoes)) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "Artigo{" + "nrevisoes=" + nrevisoes + ", idtitulo=" + idtitulo + ", revisoes=" + revisoes + '}';
    }
    
    
    public Artigo clone(){
        return new Artigo(this);
    }
    
}
