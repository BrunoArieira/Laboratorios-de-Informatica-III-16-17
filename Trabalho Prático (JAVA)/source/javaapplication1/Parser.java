/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;
import java.io.FileNotFoundException;
import java.io.FileReader;
import javax.xml.stream.XMLEventReader;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamConstants;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.events.Characters;
import javax.xml.stream.events.EndElement;
import javax.xml.stream.events.StartElement;
import javax.xml.stream.events.XMLEvent;
/**
 *
 * @author lois__000
 */
public class Parser {
    
    
    public Parser(String args) {
      int nartigos=0;
      int npalavras=0;
      boolean title = false;
      boolean idtitle = false;
      boolean timestamp = false;
      boolean page = false;
      boolean revision = false;
      boolean contributor = false;
      boolean username = false;
      boolean idcontributor = false;
      boolean idrevision = false;
      boolean text = false;
      try {
            XMLInputFactory factory = XMLInputFactory.newInstance();
            factory.setProperty(XMLInputFactory.IS_COALESCING, true);
            XMLEventReader eventReader =factory.createXMLEventReader(new FileReader(args));
            while(eventReader.hasNext()){
               XMLEvent event = eventReader.nextEvent();
               switch(event.getEventType()){
                  case XMLStreamConstants.START_ELEMENT:
                     StartElement startElement = event.asStartElement();
                     String qName = startElement.getName().getLocalPart();
                    if (qName.equalsIgnoreCase("contributor")) {
                        contributor = true;
                        revision=false;
                    }else if(qName.equalsIgnoreCase("username")){
                            username=true;
                    }else if (qName.equalsIgnoreCase("page")) {
                        contributor=false;
                        revision=false;
                        nartigos++;
                    } else if (qName.equalsIgnoreCase("title")) {
                        title = true;
                    }else if(qName.equalsIgnoreCase("id")&& !revision && !contributor){
                         idtitle=true;                
                     } else if (qName.equalsIgnoreCase("text")) {
                        text = true;
                         
                     } else if (qName.equalsIgnoreCase("revision")) {
                        revision = true;
                        
                     }else if(qName.equalsIgnoreCase("id")&& revision && !contributor){
                         idrevision=true;
                     } else if (qName.equalsIgnoreCase("timestamp")) {
                        timestamp = true;
                     
                     }else if(qName.equalsIgnoreCase("id")&& !revision && contributor){
                         
                         idcontributor=true;
                      }
                     break;
                  case XMLStreamConstants.CHARACTERS:
                     Characters characters = event.asCharacters();
                     if(title){
                        System.out.println("Title: " 
                        + characters.getData());
                        title = false;
                     }
                     if(idtitle){
                        System.out.println("IdTitle: " 
                        + characters.getData());
                        idtitle = false;
                     }
                     if(timestamp){
                        System.out.println("Timestamp: " 
                        + characters.getData());
                        timestamp = false;
                     }
                      if(idrevision){
                        System.out.println("IdRevision: " 
                        + characters.getData());
                        idrevision = false;
                     }
                      if(username){
                        System.out.println("Username: " 
                        + characters.getData());
                        username = false;
                     }
                      if(idcontributor){
                        System.out.println("IdContributor: " 
                        + characters.getData());
                        idcontributor = false;
                     }
                      if(text){
                          npalavras=contaPal(characters.getData());
                          
                        System.out.println("Npalavars: " 
                        + npalavras);
                        text = false;
                     }
                     
                     
                     break;
                  case  XMLStreamConstants.END_ELEMENT:
                     EndElement endElement = event.asEndElement();
                     if(endElement.getName().getLocalPart().equalsIgnoreCase("page")){
                        System.out.println("----------------");
                     }
                     break;
               }	
             
            }
            System.out.println(nartigos);
         } catch (FileNotFoundException e) {
            e.printStackTrace();
         } catch (XMLStreamException e) {
            e.printStackTrace();
      }
   }

public static int contaPal(String s){
    int res= 0;
    boolean word = false;
    int endOfLine = s.length() - 1;
    for (int i = 0; i < s.length(); i++) {
        if (!Character.isWhitespace(s.charAt(i)) && i != endOfLine) {
            word = true;
        } else if (Character.isWhitespace(s.charAt(i)) && word) {
            res++;
            word = false;
        } else if (!Character.isWhitespace(s.charAt(i)) && i == endOfLine) {
            res++;
        }
    }
    return res;
    } 


}