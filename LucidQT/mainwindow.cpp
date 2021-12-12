#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <shellapi.h>
#include <QFileDialog>
#include <QMessageBox>

#include "arduinowindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool startup(LPCTSTR lpApplicationName, LPCTSTR lpApplicationDir)
{
   //printf("Starting arena");
   // additional information
   STARTUPINFO si;
   PROCESS_INFORMATION pi;

   // set the size of the structures
   ZeroMemory( &si, sizeof(si) );
   si.cb = sizeof(si);
   ZeroMemory( &pi, sizeof(pi) );


  // start the program up
  if(!CreateProcess( lpApplicationName,   // the path
    NULL,        // Command line
    NULL,           // Process handle not inheritable
    NULL,           // Thread handle not inheritable
    FALSE,          // Set handle inheritance to FALSE
    NULL,              // No creation flags
    NULL,           // Use parent's environment block
    lpApplicationDir,           // Use parent's starting directory
    &si,            // Pointer to STARTUPINFO structure
    &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
                     )){
      printf( "CreateProcess failed (%d).\n", GetLastError() );
      return false;
  }

    // Wait until child process exits.
    //WaitForSingleObject( pi.hProcess, INFINITE );
    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return true;
}

void MainWindow::on_pushButton_2_released()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"",tr("Executable Files (*.exe)"));
    ui->label->setText(fileNames.join(""));
}

void MainWindow::on_pushButton_released()
{
    //printf("Button clicked");
    LPCTSTR dirToRun = L"C:/ProgramData/Lucid Vision Labs/ArenaView";
    //LPCTSTR appToRun = L"C:/ProgramData/Lucid Vision Labs/ArenaView/ArenaView.exe";
    QString labelDir = ui->label->text();

    if(labelDir.compare("") == 0){
        //printf("Empty string found");
        QMessageBox::warning(this, "Missing Executable", "There was no .exe specified. Please select ArenaView.exe in the file explorer.", QMessageBox::Ok, QMessageBox::NoButton);
        MainWindow::on_pushButton_2_released();

    }
    else{
        LPCTSTR appToRun = (LPCTSTR)(labelDir.utf16());
        printf(qPrintable(labelDir));
        if(!startup(appToRun, dirToRun)){
            QMessageBox::warning(this, "Incorrect Executable", ".exe not found. Please select ArenaView.exe in the file explorer.", QMessageBox::Ok, QMessageBox::NoButton);
            MainWindow::on_pushButton_2_released();
        }
    }

}






void MainWindow::on_pushButton_3_released()
{
    MainWindow::close();
}


void MainWindow::on_pushButton_4_released()
{
    ArduinoWindow arduinoWindow;
    arduinoWindow.setModal(true);
    arduinoWindow.exec();
    //MainWindow::hide();
}

