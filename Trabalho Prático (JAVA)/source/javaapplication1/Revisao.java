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
public class Revisao {
    private String titulo,texto, timestamp;
    private int idrevisao, numpalavras;
    private Map<Integer,Contribuidor> contribuidores;

    public Revisao() {
        this.titulo = new String();
        this.texto = new String();
        this.timestamp = new String();
        this.idrevisao =0;
        this.numpalavras =0;
        this.contribuidores =new HashMap<>();
    }
    
    
    public Revisao(String titulo, String texto, String timestamp, int idrevisao, int numpalavras, Map<Integer,Contribuidor> contribuidores) {
        this.titulo = titulo;
        this.texto = texto;
        this.timestamp = timestamp;
        this.idrevisao = idrevisao;
        this.numpalavras = numpalavras;
        this.contribuidores = new HashMap<>();
        for(Integer i : contribuidores.keySet()){
            this.contribuidores.put(i,contribuidores.get(i).clone());
        }
    }
    
    public Revisao(Revisao r) {
    this.titulo = r.getTitulo();
    this.texto = r.getTexto() ;
    this.timestamp =r.getTimestamp();
    this.idrevisao =r.getIdrevisao() ;
    this.numpalavras =r.getNumpalavras();
    this.contribuidores =r.getContribuidores();
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getTexto() {
        return texto;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public String getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(String timestamp) {
        this.timestamp = timestamp;
    }

    public int getIdrevisao() {
        return idrevisao;
    }

    public void setIdrevisao(int idrevisao) {
        this.idrevisao = idrevisao;
    }

    public int getNumpalavras() {
        return numpalavras;
    }

    public void setNumpalavras(int numpalavras) {
        this.numpalavras = numpalavras;
    }

    public Map<Integer,Contribuidor> getContribuidores() {
        Map<Integer,Contribuidor> mlc = new HashMap<>(); 
        for(Integer i : contribuidores.keySet()){
            mlc.put(i, this.contribuidores.get(i).clone());
        }
        return mlc;
    }

    public void setContribuidores(Map<Integer,Contribuidor> contribuidores) {
        this.contribuidores.clear();
        for(Integer i : contribuidores.keySet()){
            this.contribuidores.put(i, contribuidores.get(i).clone());
        }
    }

    public void addContribuidor(int idrevisao, Contribuidor c){
        this.contribuidores.put(idrevisao,c.clone());
    }
    
    public Contribuidor contribuidor(int idrevisao){
      return this.contribuidores.get(idrevisao);
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
        final Revisao other = (Revisao) obj;
        if (this.idrevisao != other.idrevisao) {
            return false;
        }
        if (this.numpalavras != other.numpalavras) {
            return false;
        }
        if (!Objects.equals(this.titulo, other.titulo)) {
            return false;
        }
        if (!Objects.equals(this.texto, other.texto)) {
            return false;
        }
        if (!Objects.equals(this.timestamp, other.timestamp)) {
            return false;
        }
        if (!Objects.equals(this.contribuidores, other.contribuidores)) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 61 * hash + Objects.hashCode(this.titulo);
        hash = 61 * hash + Objects.hashCode(this.texto);
        hash = 61 * hash + Objects.hashCode(this.timestamp);
        hash = 61 * hash + this.idrevisao;
        hash = 61 * hash + this.numpalavras;
        hash = 61 * hash + Objects.hashCode(this.contribuidores);
        return hash;
    }

 
    @Override
    public String toString() {
        return "Revisao{" + "titulo=" + titulo + ", texto=" + texto + ", timestamp=" + timestamp + ", idrevisao=" + idrevisao + ", numpalavras=" + numpalavras + ", contribuidores=" + contribuidores + '}';
    }
    
    public Revisao clone(){
      return new Revisao(this);
    }  

}
