#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    ui->lista_punt->hide();
    ui->l_punt->hide();

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::jugar(){
    int punt_1, punt_2; tamano=ui->tam->value();
    string mejor_palabra, puntuaciones="", palabra_introducida=ui->lineEdit->text().toUtf8().constData();

	for(unsigned int i=0;i<palabra_introducida.size();i++){
		palabra_introducida[i]=tolower(palabra_introducida[i]);
	}

    if (letras.formable(palabra_introducida)) {
        if(letras.enDiccionario(palabra_introducida)){
            if(modo_tamano){
                string mejor_palabra;
                ui->mensaje_info->setText((string("Tamaño de ")+palabra_introducida+string(": ")+to_string(palabra_introducida.size())).c_str());

                mejor_palabra = letras.mejor_palabra_tamano();

                ui->mi_sol->setText((string("Mi solución: ")+mejor_palabra).c_str());
                ui->tam_mi_sol->setText((string("Tamaño: ")+to_string(mejor_palabra.size())).c_str());
                if (palabra_introducida.size() > mejor_palabra.size()) {
                     ui->Mensajes->setText("<b>Has ganado</b>");
                } else {
                    if (palabra_introducida.size() == mejor_palabra.size())
                        ui->Mensajes->setText("<b>Empate</b>");
                    else
                        ui->Mensajes->setText("<b>Has perdido</b>");
                }

                ui->comp->setText("Jugar de nuevo");
                texto_boton=false;

            } else {
                punt_1=letras.puntuacion_palabra(palabra_introducida);
                ui->mensaje_info->setText((string("Puntuación de ")+palabra_introducida+string(": ")+to_string(letras.puntuacion_palabra(palabra_introducida))).c_str());
                mejor_palabra = letras.mejor_palabra_tamano();
                punt_2=letras.puntuacion_palabra(mejor_palabra);
                ui->mi_sol->setText((string("Mi solución: ")+mejor_palabra).c_str());
                ui->tam_mi_sol->setText((string("Puntuación: ")+to_string(letras.puntuacion_palabra(mejor_palabra))).c_str());
                if (punt_1 > punt_2) {
                     ui->Mensajes->setText("<b>Has ganado</b>");
                } else {
                    if (punt_1 == punt_2)
                        ui->Mensajes->setText("<b>Empate</b>");
                    else
                        ui->Mensajes->setText("<b>Has perdido</b>");
                }

                ui->comp->setText("Jugar de nuevo");
                texto_boton=false;
            }
        }
        else{
            ui->Mensajes->setText((string("<b>")+palabra_introducida+ " no está en el diccionario</b>").c_str());
        }
    }
    else{
        ui->Mensajes->setText((string("<b>")+palabra_introducida+ " no se puede generar con las letras dadas</b>").c_str());
    }

}

void MainWindow::repetir(){
    if(texto_boton)
        jugar();
    else{
        tamano=ui->tam->value();
        if(!letras.inicializar_letras(tamano)){
            ui->Mensajes->setText("Error de tamaño");
        }else{
			texto_boton=true;
			ui->comp->setText("Comprobar");
			ui->Mensajes->setText("");
			ui->mensaje_info->setText("");
			ui->tam_mi_sol->setText("Tamaño: ");
			ui->mi_sol->setText("Mi solución: ");
			ui->lineEdit->setText("");
			ui->lista_punt->setText(letras.getPuntuacion().c_str());
			ui->lista_disp->setText(letras.getLetras_admitidas().c_str());
		}
    }
}
void MainWindow::on_comp_clicked(){
    repetir();
}

void MainWindow::on_lineEdit_returnPressed(){
    repetir();
}

void MainWindow::on_tam_valueChanged(){
    tamano=ui->tam->value();
    if(!letras.inicializar_letras(tamano)){
        ui->Mensajes->setText("Error de tamaño");
    }
    ui->lista_punt->setText(letras.getPuntuacion().c_str());
    ui->lista_disp->setText(letras.getLetras_admitidas().c_str());

}

void MainWindow::on_m_punt_clicked(){
    ui->tam_mi_sol->setText("Puntuación:");
    modo_tamano=false;
    ui->lista_punt->show();
    ui->l_punt->show();
    ui->lista_disp->resize(ui->lista_disp->width(),91);
    ui->lista_punt->setText(letras.getPuntuacion().c_str());
}

void MainWindow::on_m_tam_clicked(){
    ui->tam_mi_sol->setText("Tamaño:");
    modo_tamano=true;
    ui->lista_punt->hide();
    ui->l_punt->hide();
    ui->lista_disp->resize(ui->lista_disp->width(),201);
}

void MainWindow::bloquear(bool estado){
    ui->comp->setEnabled(estado);
    ui->tam->setEnabled(estado);
    ui->m_tam->setEnabled(estado);
    ui->m_punt->setEnabled(estado);
    ui->lineEdit->setEnabled(estado);
    ui->lista_punt->setEnabled(estado);
    ui->lista_disp->setEnabled(estado);
}

void MainWindow::on_cargar_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Cargar diccionario"), "",
            tr("diccionario (*.txt);;All Files (*)"));
    QString fileName2 = QFileDialog::getOpenFileName(this,
            tr("Cargar fichero de puntos"), "",
            tr("puntos (*.txt);;All Files (*)"));

    if (letras.cargar_diccionario(fileName.toUtf8().constData())) {
        if (letras.cargar_datos(fileName2.toUtf8().constData())) {
            tamano=ui->tam->value();
            if(letras.inicializar_letras(tamano)){
                bloquear(true);
                ui->tam->setMaximum(letras.getBolsa_letras().size());
                ui->lista_disp->setText(letras.getLetras_admitidas().c_str());
                ui->Mensajes->setText("");
            }
            else{
                ui->Mensajes->setText("Error de tamaño");
				bloquear(false);
            }
        }
        else{
            ui->Mensajes->setText("<b>Error leyendo archivos</b>");
			bloquear(false);
        }
    }else{
        ui->Mensajes->setText("<b>Error leyendo archivos</b>");
		bloquear(false);
    }
}
