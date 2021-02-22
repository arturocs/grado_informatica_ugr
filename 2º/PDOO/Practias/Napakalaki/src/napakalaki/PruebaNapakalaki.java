/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;

import java.util.ArrayList;
import java.util.Arrays;

/**
 *
 * @author arturo
 */
public class PruebaNapakalaki {

    /**
     * @param args the command line arguments
     */
    static ArrayList<Monster> monstruos = new ArrayList();
    static void aniadirmontruos(){
    
    //3 Byakhees de balanza
    BadConsequence badConsequence = new BadConsequence("Pierdes tu armadura visible y otra oculta", 0,
    new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList(Arrays.asList(TreasureKind.ONEHAND)));
    Prize prize = new Prize(2,1);
    monstruos.add(new Monster("3 Byakhees de balanza", 8, badConsequence, prize));

    //Tecnochtitlan
    badConsequence = new BadConsequence("Embobados con el lindo primigenio te descartas de tu casco visible",0,
    new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("Tecnochtitlan", 2, badConsequence, prize));

    //El sopor de Dunwich
    badConsequence = new BadConsequence ("El primordial bostezo contagioso. Pierdes el calzado visible",
    0,new ArrayList(Arrays.asList(TreasureKind.SHOES)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("El sopor de Dunwich",2,badConsequence,prize));

    //Demonios de Magaluf
    badConsequence = new BadConsequence ("Te atrapan para llevarte de fiesta y te dejan caer en mitad del vuelo."
        + "Descarta 1 mano visible y 1 mano oculta",0,new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList(Arrays.asList(TreasureKind.ONEHAND)));
    prize = new Prize(4,1);
    monstruos.add(new Monster("Demonios de Magaluf",2,badConsequence,prize));

    //El gorron en el umbral
    badConsequence = new BadConsequence ("Pierdes todos tus tesoros visibles",0,Integer.MAX_VALUE,0);
    prize = new Prize(3,1);
    monstruos.add(new Monster("El gorron en el umbral",13,badConsequence,prize));

    //H.P Munchcraft
    badConsequence = new BadConsequence ("Pierdes la armadura visible",0,
    new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList());
    prize = new Prize(2,1);
    monstruos.add(new Monster("H.P Munchcraft",6,badConsequence,prize));

    //Necrofalo
    badConsequence = new BadConsequence ("Sientes bichos bajo la ropa. Descarga la armadura visible",0,
    new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("Necrofalo",13,badConsequence,prize));

    //El rey de rosado
    badConsequence = new BadConsequence("Pierdes 5 niveles y 3 tesoros visibles",5,3,0);
    prize = new Prize(3,2);
    monstruos.add(new Monster("El rey de rosado",11,badConsequence,prize));

    //Flecher
    badConsequence = new BadConsequence("Toses los pulmones y pierdes 2 niveles",2,0,0);
    prize = new Prize(1,1);
    monstruos.add(new Monster("Flecher",2,badConsequence,prize));

    //Los hondos
    badConsequence = new BadConsequence("Estos monstruos resultan bastante superficiales y te aburren mortalmente. Estas muerto", true);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Los hondos", 8, badConsequence, prize));
    
    //Semillas Cthulhu
    badConsequence = new BadConsequence("Pierdes 2 niveles y 2 tesoros ocultos", 2, 0, 2);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Semillas Cthulhu",4 , badConsequence, prize));
    
    //Dameargo
    badConsequence = new BadConsequence("Te intentas escaquear. Pierdes una mano visible.", 0, new ArrayList(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList());
    prize = new Prize(2,1);
    monstruos.add(new Monster("Dameargo",1 , badConsequence, prize));
    
    //Pollipólipo volante
    badConsequence = new BadConsequence("Da mucho asquito. Pierdes 3 niveles.", 3, 0, 0);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Pollipólipo volante",3 , badConsequence, prize));
    
    //Yskhtihyssg-Goth
    badConsequence = new BadConsequence("No le hace gracia que pronuncien mal su nombre. Estas muerto", true);
    prize = new Prize(3,1);
    monstruos.add(new Monster("Yskhtihyssg-Goth", 14, badConsequence, prize));
    
    //Familia feliz
    badConsequence = new BadConsequence("La familia te atrapa. Estás muerto.", true);
    prize = new Prize(3,1);
    monstruos.add(new Monster("Familia feliz", 1, badConsequence, prize));
    
    //Roboggoth
    badConsequence = new BadConsequence("La quinta directiva primaria te obliga a perder 2 niveles y un tesoro 2 manos visible", 2, new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS)),new ArrayList() );
    prize = new Prize(2,1);
    monstruos.add(new Monster("Roboggoth", 8, badConsequence, prize));
    
    //El espia sordo
    badConsequence = new BadConsequence("Te asusta en la noche. Pierdes un casco visible", 0, new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList() );
    prize = new Prize(1,1);
    monstruos.add(new Monster("El espia sordo", 5, badConsequence, prize));
    
    //Tongue
    badConsequence = new BadConsequence("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles", 2,5,0 );
    prize = new Prize(2,1);
    monstruos.add(new Monster("Tongue", 19, badConsequence, prize));
    
    //Bicéfalo
    badConsequence = new BadConsequence("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos", 3,new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS,TreasureKind.ONEHAND,TreasureKind.ONEHAND)),new ArrayList() );
    prize = new Prize(2,1);
    monstruos.add(new Monster("Bicéfalo", 21, badConsequence, prize));
    
    }
    
    //Funcion que devuelve los monstruos con un nivel superior a 10
    static ArrayList<Monster> masDeDiez(){
    ArrayList<Monster> resultado =new ArrayList();
    
        for(Monster m:monstruos){
            if(m.getCombatLevel()>10)
                resultado.add(m);
        }
        return resultado;
    }
    
//Funcion que devuelve los montruos que unicamente causan perdida de nivel como mal rollo
    static ArrayList<Monster> perdidaDeNivel(){
    ArrayList<Monster> resultado =new ArrayList();
    
        for(Monster m:monstruos){
            if(m.getBc().getLevels() >0 && m.getBc().isDeath()==false && m.getBc().getnHiddenTreasures()==0 && m.getBc().getnVisibleTreasures() == 0 && m.getBc().getSpecificHiddenTreasures().isEmpty() ==true && m.getBc().getSpecificVisibleTreasures().isEmpty() == true )
                resultado.add(m);
        }
        return resultado;
    }
//Funcion que devuelve los monstruos cuyo buen rollo indica una ganancia de nivel superior a 1
    static ArrayList<Monster> nivelSup1(){
    ArrayList<Monster> resultado =new ArrayList();
    
        for(Monster m:monstruos){
            if(m.getPrize().getLevel()>1)
                resultado.add(m);
        }
        return resultado;
    }    
//Funcion que devuelve los monstruos cuyo mal rollo supone la pérdida de un determinado tipo de tesoro   
    static ArrayList<Monster> perdidaDeTesoro(TreasureKind tesoro){
    ArrayList<Monster> resultado =new ArrayList();
    
        for(Monster m:monstruos){
            if(m.getBc().getSpecificHiddenTreasures().contains(tesoro) || m.getBc().getSpecificVisibleTreasures().contains(tesoro))
                resultado.add(m);
        }
        return resultado;
    }
    
    
    
   /* public static void main(String[] args) {
        // TODO code application logic here
        Prize prize1=new Prize(3,0);
        System.out.println(prize1.toString());  
         Prize prize2=new Prize(4,0);
        System.out.println(prize2.toString()); 
        
        //Prueba de funciones
        aniadirmontruos();
       
        ArrayList<Monster> resultado_masDeDiez = masDeDiez();
        System.out.println(resultado_masDeDiez);
        
        ArrayList<Monster> resultado_perdidaDeNivel = perdidaDeNivel();
        System.out.println(resultado_perdidaDeNivel);
        
        ArrayList<Monster> resultado_nivelSup1 = nivelSup1();
        System.out.println(resultado_nivelSup1);
        
        ArrayList<Monster> resultado_perdidaDeTesoro = perdidaDeTesoro(TreasureKind.ARMOR);
        System.out.println(resultado_perdidaDeTesoro);
        
        resultado_perdidaDeTesoro = perdidaDeTesoro(TreasureKind.ONEHAND);
        System.out.println(resultado_perdidaDeTesoro);
        
        resultado_perdidaDeTesoro = perdidaDeTesoro(TreasureKind.BOTHHANDS);
        System.out.println(resultado_perdidaDeTesoro);
        
        resultado_perdidaDeTesoro = perdidaDeTesoro(TreasureKind.HELMET);
        System.out.println(resultado_perdidaDeTesoro);
        
        resultado_perdidaDeTesoro = perdidaDeTesoro(TreasureKind.SHOES);
        System.out.println(resultado_perdidaDeTesoro);
        
    }*/
    
}
