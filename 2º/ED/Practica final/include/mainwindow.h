#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Letras.h"


/**
 * @brief T.D.A. MainWindow
 *
 * Clase destinada a la representación gráfica de la aplicación
 *
 *
 *
 * @author Arturo Cortés Sánchez
 * @author Rubén Mogica Garrido
 * @date Diciembre 2018
 */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
    * @brief Constructor de la clase
    */
    explicit MainWindow(QWidget *parent = nullptr);
    /**
    * @brief Destructor de la clase
    */
    ~MainWindow();
private slots:
    /**
    * @brief Método ejecutado cuando se pulsa el botón de comprobar para ver la solución
    */
     void on_comp_clicked();
    /**
    * @brief Método ejecutado cuando se pulsa enter para ver la solución
    */
     void on_lineEdit_returnPressed();
    /**
    * @brief Método ejecutado cuando cambia el tamaño de las letras que actualiza la información
    */
     void on_tam_valueChanged();
    /**
    * @brief Método para pasar al modo puntuación
    */     
     void on_m_punt_clicked();
    /**
    * @brief Método para pasar al modo tamaño
    */
     void on_m_tam_clicked();
    /**
    * @brief Método para cargar los archivos del juego
    */
     void on_cargar_clicked();

private:
    Letras letras;      /**< Letras con las que jugar*/
    Ui::MainWindow *ui; /**< Objeto de la interfaz*/
    int tamano;         /**< Número de letras del juego*/
    bool texto_boton=true;  /**< Booleano para el texto a mostrar en el boton para saber si se va a comprobar o a jugar de nuevo*/
    bool modo_tamano=true;  /**< Booleano para determinar el modo de juego*/
    
    /**
    * @brief Método llevar a cabo el juego, obteniendo la respuesta del jugador y, si ha sido válida,
    * obtener también la palabra calculada y compararlas para determinar el ganador.
    */
    void jugar();
    /**
    * @brief Método para reiniciar los valores del juego de cara a una nueva partida
    */

    void repetir();

	/**
    * @brief Método para controlar los botones que se pueden pulsar
    */

    void bloquear(bool estado);

};

#endif // MAINWINDOW_H
