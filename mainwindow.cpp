#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgProduction.h"
#include "dlgHelp.h"
#include <string>
#include "tinyxml2.h"
#include "Logger.h"
#include <QFileDialog>
#include <iostream>
#include <fstream>


wndMain::wndMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wndMain)
{
    ui->setupUi(this);
	connect(ui->btnGenerate, SIGNAL(clicked()), this , SLOT(generate()));
	connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addProduction()));
	connect(ui->btnRemove, SIGNAL(clicked()), this, SLOT(removeProduction()));
	connect(ui->btnClear, SIGNAL(clicked()), this, SLOT(clearCamera()));
	connect(ui->btnTextureBranch, SIGNAL(clicked()), this, SLOT(assignBranchTexture()));
	connect(ui->btnTextureLeaf, SIGNAL(clicked()), this, SLOT(assignLeafTexture()));

	connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(exit()));
	connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(help()));
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(open()));
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(save()));
	connect(ui->actionExport, SIGNAL(triggered()), this, SLOT(exportObj()));

	connect(ui->actionShadow, SIGNAL(toggled(bool)), this, SLOT(isShadow(bool)));
	connect(ui->actionAnimation, SIGNAL(toggled(bool)), this, SLOT(isAnimation(bool)));
	connect(ui->actionWireframe, SIGNAL(toggled(bool)), this, SLOT(isWireframe(bool)));

	Logger::getInstance()->set(ui->txtLog);

	ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Predecessor" << "Successor" << "Chance");
	ui->tableWidget->setColumnWidth(0, 50);
	ui->tableWidget->setColumnWidth(1, 250);
	ui->tableWidget->setColumnWidth(2, 60);
	setWindowIcon(QIcon(":/images/icon.ico"));




}

wndMain::~wndMain()
{
    delete ui;
}


void wndMain::open()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open XML File:"), QDir::currentPath(), "XML File (*.xml);;");

	if (!filename.isEmpty()) {
		Logger::getInstance()->write("XML File Parsing...",true);
		
		tinyxml2::XMLDocument doc;
		if (doc.LoadFile(filename.toStdString().c_str()) == 0) {

			tinyxml2::XMLElement* xmlLsystem = doc.FirstChildElement("lsystem");
			if (xmlLsystem == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: lsystem tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlProductions = xmlLsystem->FirstChildElement("productions");
			if (xmlProductions == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: productions tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlAxiom = xmlLsystem->FirstChildElement("axiom");
			if (xmlAxiom == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: axiom tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlAngle = xmlLsystem->FirstChildElement("angle");
			if (xmlAngle == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: angle tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlBranch = xmlLsystem->FirstChildElement("branch");
			if (xmlBranch == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: branch tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlLeaf = xmlLsystem->FirstChildElement("leaf");
			if (xmlLeaf == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: leaf tag not found");
				return;
			}

			tinyxml2::XMLElement* xmlLength = xmlBranch->FirstChildElement("length");
			if (xmlLength == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: length tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlThickness = xmlBranch->FirstChildElement("thickness");
			if (xmlThickness == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: thickness tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlApproximation = xmlBranch->FirstChildElement("approximation");
			if (xmlApproximation == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: approximation tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlHermiteSteps = xmlBranch->FirstChildElement("hermitesteps");
			if (xmlHermiteSteps == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: hermitesteps tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlHermiteTangent = xmlBranch->FirstChildElement("hermitetangent");
			if (xmlHermiteTangent == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: hermitetangent tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlHermiteTangent2 = xmlBranch->FirstChildElement("hermitetangent2");
			if (xmlHermiteTangent2 == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: hermitetangent2 tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlTangentMinDist = xmlBranch->FirstChildElement("tangentmindist");
			if (xmlTangentMinDist == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: tangentmindist tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlDecreaseFactor = xmlBranch->FirstChildElement("decreasefactor");
			if (xmlDecreaseFactor == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: decreasefactor tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlLeafScaleX = xmlLeaf->FirstChildElement("scalex");
			if (xmlLeafScaleX == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: scalex tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlLeafScaleY = xmlLeaf->FirstChildElement("scaley");
			if (xmlLeafScaleY == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: scaley tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlLeafBending = xmlLeaf->FirstChildElement("bending");
			if (xmlLeafBending == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: bending tag not found");
				return;
			}
			tinyxml2::XMLElement* xmlLeafDecrease = xmlLeaf->FirstChildElement("decreasefactor");
			if (xmlLeafDecrease == nullptr) {
				Logger::getInstance()->error("XML Parsing Error: decreasefactor tag not found");
				return;
			}

			int iterations, approximation, hermitesteps;
			float angle, length, thickness, hermitetangent, hermitetangent2, mindist, decreasefactor, leafScaleX, leafScaleY, leafBending, decreasefactorleaf;

			xmlProductions->QueryIntAttribute("iterations", &iterations);
			const char* axiom = xmlAxiom->GetText();
			const char* imageBranch = xmlBranch->Attribute("image");
			xmlAngle->QueryFloatText(&angle);
			xmlLength->QueryFloatText(&length);
			xmlThickness->QueryFloatText(&thickness);
			xmlApproximation->QueryIntText(&approximation);
			xmlHermiteSteps->QueryIntText(&hermitesteps);
			xmlHermiteTangent->QueryFloatText(&hermitetangent);
			xmlHermiteTangent2->QueryFloatText(&hermitetangent2);
			xmlTangentMinDist->QueryFloatText(&mindist);
			xmlDecreaseFactor->QueryFloatText(&decreasefactor);
			const char* imageLeaf = xmlLeaf->Attribute("image");
			xmlLeafScaleX->QueryFloatText(&leafScaleX);
			xmlLeafScaleY->QueryFloatText(&leafScaleY);
			xmlLeafBending->QueryFloatText(&leafBending);
			xmlLeafDecrease->QueryFloatText(&decreasefactorleaf);
			std::vector<SRules> rules;
			ui->tableWidget->clear();
			ui->tableWidget->setRowCount(0);
			ui->tableWidget->setColumnWidth(0, 50);
			ui->tableWidget->setColumnWidth(1, 200);
			ui->tableWidget->setColumnWidth(2, 50);

			for (tinyxml2::XMLElement* xmlProduction = xmlProductions->FirstChildElement("production"); xmlProduction != NULL; xmlProduction = xmlProduction->NextSiblingElement("production"))
			{
				const char *rule = xmlProduction->Attribute("rule");
				float chance;
				xmlProduction->QueryFloatAttribute("chance", &chance);
				const char *successor = xmlProduction->GetText();
				rules.push_back(SRules(*rule, std::string(successor), chance));
				int rowcount = ui->tableWidget->rowCount();
				ui->tableWidget->insertRow(rowcount);
				ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem(QString(rule)));
				ui->tableWidget->setItem(rowcount, 1, new QTableWidgetItem(QString(successor)));
				ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(QString(QString::number(chance))));

			}
			ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Rule" << "Successor" << "Chance");
			ui->lblBranchTexture->setText(QString(imageBranch));
			ui->lblLeafTexture->setText(QString(imageLeaf));
			ui->txtAxiom->setText(QString(axiom));
			ui->sBoxIterations->setValue(iterations);
			ui->sBoxAngle->setValue(angle);
			ui->sBoxCylinder->setValue(approximation);
			ui->sBoxHermite->setValue(hermitesteps);
			ui->sBoxTangent->setValue(hermitetangent);
			ui->sBoxTangent2->setValue(hermitetangent2);
			ui->sBoxLength->setValue(length);
			ui->sBoxThickness->setValue(thickness);
			ui->sBoxLeafX->setValue(leafScaleX);
			ui->sBoxLeafY->setValue(leafScaleY);
			ui->sBoxDecrease->setValue(decreasefactor);
			ui->sBoxDecreaseLeaf->setValue(decreasefactorleaf);
			ui->sBoxBending->setValue(leafBending);
			ui->sBoxDist->setValue(mindist);

			Logger::getInstance()->write("XML File Parsed");
			ui->openGLWidget->setTextures(QString(imageBranch), QString(imageLeaf));
			ui->openGLWidget->generate(rules, std::string(axiom), iterations, angle, length, thickness, decreasefactor, leafScaleX, leafScaleY, leafBending, decreasefactorleaf, hermitetangent, hermitetangent2, hermitesteps, approximation, mindist);
		}
		else {
			Logger::getInstance()->write("Failed to open xml file in path: "+filename);
		}
	}
	
}


void wndMain::save()
{

	QString filename = QFileDialog::getSaveFileName(this, tr("Save XML File:"), QDir::currentPath(), "XML File (*.xml);;");
	if (!filename.isEmpty()) {
		QString axiom = ui->txtAxiom->text();
		int iterations = ui->sBoxIterations->value();
		float angle = ui->sBoxAngle->value();
		float approximation = ui->sBoxCylinder->value();
		int hermitesteps = ui->sBoxHermite->value();
		float hermitetangent = ui->sBoxTangent->value();
		float hermitetangent2 = ui->sBoxTangent2->value();
		float length = ui->sBoxLength->value();
		float thickness = ui->sBoxThickness->value();
		float decreasefactor = ui->sBoxDecrease->value();
		float leafScaleX = ui->sBoxLeafX->value();
		float leafScaleY = ui->sBoxLeafY->value();
		float leafDecrease = ui->sBoxDecreaseLeaf->value();
		float leafBending = ui->sBoxBending->value();
		float mindist = ui->sBoxDist->value();

		tinyxml2::XMLDocument doc;
		tinyxml2::XMLNode * xmlLsystem = doc.NewElement("lsystem");
		doc.InsertFirstChild(xmlLsystem);

		tinyxml2::XMLElement * xmlProductions = doc.NewElement("productions");
		xmlProductions->SetAttribute("iterations", iterations);
		xmlLsystem->InsertEndChild(xmlProductions);

		for (int i = 0; i < ui->tableWidget->rowCount(); i++) {

			QTableWidgetItem *rule = ui->tableWidget->item(i, 0);
			QTableWidgetItem *successor = ui->tableWidget->item(i, 1);
			QTableWidgetItem *chance = ui->tableWidget->item(i, 2);

			tinyxml2::XMLElement * productionElement = doc.NewElement("production");
			productionElement->SetText(successor->text().toStdString().c_str());
			productionElement->SetAttribute("rule", rule->text().toStdString().c_str());
			productionElement->SetAttribute("chance", chance->text().toFloat());
			xmlProductions->InsertEndChild(productionElement);
		}


		tinyxml2::XMLElement * xmlAxiom = doc.NewElement("axiom");
		xmlAxiom->SetText(axiom.toStdString().c_str());
		xmlLsystem->InsertEndChild(xmlAxiom);

		tinyxml2::XMLElement * xmlAngle = doc.NewElement("angle");
		xmlAngle->SetText(angle);
		xmlLsystem->InsertEndChild(xmlAngle);

		tinyxml2::XMLElement * xmlBranch = doc.NewElement("branch");
		xmlBranch->SetAttribute("image", ui->lblBranchTexture->text().toStdString().c_str());
		xmlLsystem->InsertEndChild(xmlBranch);

		tinyxml2::XMLElement * xmlLength = doc.NewElement("length");
		xmlLength->SetText(length);
		xmlBranch->InsertFirstChild(xmlLength);

		tinyxml2::XMLElement * xmlThickness = doc.NewElement("thickness");
		xmlThickness->SetText(thickness);
		xmlBranch->InsertEndChild(xmlThickness);

		tinyxml2::XMLElement * xmlApproximation = doc.NewElement("approximation");
		xmlApproximation->SetText(approximation);
		xmlBranch->InsertEndChild(xmlApproximation);

		tinyxml2::XMLElement * xmlHermiteSteps = doc.NewElement("hermitesteps");
		xmlHermiteSteps->SetText(hermitesteps);
		xmlBranch->InsertEndChild(xmlHermiteSteps);

		tinyxml2::XMLElement * xmlHermiteTangent = doc.NewElement("hermitetangent");
		xmlHermiteTangent->SetText(hermitetangent);
		xmlBranch->InsertEndChild(xmlHermiteTangent);

		tinyxml2::XMLElement * xmlHermiteTangent2 = doc.NewElement("hermitetangent2");
		xmlHermiteTangent2->SetText(hermitetangent2);
		xmlBranch->InsertEndChild(xmlHermiteTangent2);

		tinyxml2::XMLElement * xmlTangentMinDist = doc.NewElement("tangentmindist");
		xmlTangentMinDist->SetText(mindist);
		xmlBranch->InsertEndChild(xmlTangentMinDist);

		tinyxml2::XMLElement * xmlDecrease = doc.NewElement("decreasefactor");
		xmlDecrease->SetText(decreasefactor);
		xmlBranch->InsertEndChild(xmlDecrease);

		tinyxml2::XMLElement * xmlLeaf = doc.NewElement("leaf");
		xmlLeaf->SetAttribute("image", ui->lblLeafTexture->text().toStdString().c_str());
		xmlLsystem->InsertEndChild(xmlLeaf);

		tinyxml2::XMLElement * xmlLeafScaleX = doc.NewElement("scalex");
		xmlLeafScaleX->SetText(leafScaleX);
		xmlLeaf->InsertEndChild(xmlLeafScaleX);

		tinyxml2::XMLElement * xmlLeafScaleY = doc.NewElement("scaley");
		xmlLeafScaleY->SetText(leafScaleY);
		xmlLeaf->InsertEndChild(xmlLeafScaleY);

		tinyxml2::XMLElement * xmlLeafBending = doc.NewElement("bending");
		xmlLeafBending->SetText(leafBending);
		xmlLeaf->InsertEndChild(xmlLeafBending);

		tinyxml2::XMLElement * xmlLeafDecrease = doc.NewElement("decreasefactor");
		xmlLeafDecrease->SetText(leafDecrease);
		xmlLeaf->InsertEndChild(xmlLeafDecrease);

		doc.SaveFile(filename.toStdString().c_str());

		Logger::getInstance()->write("XML File Saved");
	}



}

void wndMain::addProduction()
{
	dlgProduction *production = new dlgProduction();
	production->setModal(true);
	production->exec();
	int rowcount = ui->tableWidget->rowCount();
	QString rule = production->getRule();
	QString product = production->getProduction();
	QString chance = production->getChance();

	if (!rule.isEmpty()) {
		if (!product.isEmpty()) {
			ui->tableWidget->insertRow(rowcount);
			ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem(rule));
			ui->tableWidget->setItem(rowcount, 1, new QTableWidgetItem(product));
			ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(chance));
		}else{
			Logger::getInstance()->error("No entry in production");
		}
	}
	else {
		Logger::getInstance()->error("No entry in rule");
	}
	
	Logger::getInstance()->write("Production added");
}



void wndMain::removeProduction()
{
	QList<QTableWidgetItem*> selectionRangeList = ui->tableWidget->selectedItems();
	int rowIndex;
	QListIterator<QTableWidgetItem*> selectionRangeListIter(selectionRangeList);

	while (selectionRangeListIter.hasNext()) {
		rowIndex = ((int)((QTableWidgetItem*)selectionRangeListIter.next())->row());
		ui->tableWidget->removeRow(rowIndex);
	}
	Logger::getInstance()->write("Production removed");

}

void wndMain::exportObj()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Export OBJ and MAT File:"), QDir::currentPath(), "OBJ File (*.obj);;");
	if (!filename.isEmpty()) {
		std::ofstream myfile;
		QVector<QVector3D> branches = ui->openGLWidget->getBranchData();
		QVector<QVector3D> leafs = ui->openGLWidget->getLeafData();
		QVector<int> leafIndices = ui->openGLWidget->getLeafIndices();
		QVector<int> branchIndices = ui->openGLWidget->getBranchIndices();

		Logger::getInstance()->write("Exporting OBJ and MAT File. This might take a while...",true);

		std::string matname = filename.section(".", 0, 0).section("/",-1,-1).toStdString() + ".mtl";
		myfile.open(filename.toStdString());
		myfile << "mtllib "<< matname << "\n";

		int branchIndex = 1;
		for (int i = 0; i < branches.length(); i += 3) {
			myfile << "v " << branches[i].x() << " " << branches[i].y() << " " << branches[i].z() << "\n";
			branchIndex++;
		}
		Logger::getInstance()->write("Branches vertices data written", true);
		
		for (int i = 0; i < leafs.length(); i += 3) {
			myfile << "v " << leafs[i].x() << " " << leafs[i].y() << " " << leafs[i].z() << "\n";
		}
		Logger::getInstance()->write("Leafs vertices data written", true);

		for (int i = 2; i < branches.length(); i += 3) {
			myfile << "vt " << branches[i].x() << " " << branches[i].y() << "\n";
		}
		Logger::getInstance()->write("Branches uv data written", true);

		for (int i = 2; i < leafs.length(); i += 3) {
			myfile << "vt " << leafs[i].x() << " " << leafs[i].y() << "\n";
		}
		Logger::getInstance()->write("Leafs uv data written", true);

		for (int i = 1; i < branches.length(); i += 3) {
			myfile << "vn " << branches[i].x() << " " << branches[i].y() << " " << branches[i].z() << "\n";
		}
		Logger::getInstance()->write("Branches normals data written", true);

		for (int i = 1; i < leafs.length(); i += 3) {
			myfile << "vn " << leafs[i].x() << " " << leafs[i].y() << " " << leafs[i].z() << "\n";
		}
		Logger::getInstance()->write("Leafs normals data written", true);

		Logger::getInstance()->write("Writing branch faces data...", true);
		QString branchTexture = ui->lblBranchTexture->text();
		std::string branchTextureFile = branchTexture.section("/", -1, -1).toStdString();
		myfile << "usemtl " << branchTextureFile << "\n";
		for (int i = 0; i < branchIndices.length(); i += 3) {
			myfile << "f " << branchIndices[i]+1 << "/" << branchIndices[i] + 1 << "/" << branchIndices[i] + 1 << " ";
			myfile << branchIndices[i + 1] + 1 << "/" << branchIndices[i + 1] + 1 << "/" << branchIndices[i + 1] + 1 << " ";
			myfile << branchIndices[i + 2] + 1 << "/" << branchIndices[i + 2] + 1 << "/" << branchIndices[i + 2] + 1 << "\n";
		}

		Logger::getInstance()->write("Writing leafs faces data...", true);
		QString leafTexture = ui->lblLeafTexture->text();
		std::string leafTextureFile = leafTexture.section("/", -1, -1).toStdString();
		myfile << "usemtl " << leafTextureFile << "\n";
		for (int i = 0; i < leafIndices.length(); i += 3) {
			myfile << "f " << branchIndex + leafIndices[i] << "/" << branchIndex + leafIndices[i] << "/" << branchIndex + leafIndices[i] << " ";
			myfile << branchIndex + leafIndices[i + 1] << "/" << branchIndex + leafIndices[i + 1] << "/" << branchIndex + leafIndices[i + 1] << " ";
			myfile << branchIndex + leafIndices[i + 2] << "/" << branchIndex + leafIndices[i + 2] << "/" << branchIndex + leafIndices[i + 2] << "\n";
		}

		myfile.close();

		Logger::getInstance()->write("OBJ Export done. Starting to write the MAT file...", true);
		std::ofstream matfile;
		matfile.open(matname);
		matfile << "newmtl " << branchTextureFile << "\n";
		matfile << "Ka 0.5000 0.5000 0.5000\n" << "Kd 0.8000 0.8000 0.8000\n";
		matfile << "illum 1\n" << "map_Ka " << branchTextureFile << "\n";
		matfile << "map_Kd " << branchTextureFile << "\n\n";
		matfile << "newmtl " << leafTextureFile << "\n";
		matfile << "Ka 0.5000 0.5000 0.5000\n" << "Kd 0.8000 0.8000 0.8000\n";
		matfile << "illum 1\n" << "map_Ka " << leafTextureFile << + "\n";
		matfile << "map_Kd " << leafTextureFile << "\n";

		matfile.close();
		Logger::getInstance()->write("Export finished", true);
	}

}

void wndMain::clearCamera()
{
	ui->openGLWidget->resetCamera();
	Logger::getInstance()->write("Camera reseted");
}

void wndMain::exit()
{
	QApplication::quit();
}

void wndMain::help()
{
	dlgHelp *help = new dlgHelp();
	help->show();
}

void wndMain::assignBranchTexture()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open Image File:"), QDir::currentPath(), "JPEG File (*.jpg);;PNG File (*.png);;");
	if (!filename.isEmpty()) {
		ui->lblBranchTexture->setText(filename);
		ui->openGLWidget->setTextures(QString(ui->lblBranchTexture->text()), QString(ui->lblLeafTexture->text()));
	}

}

void wndMain::assignLeafTexture()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open Image File:"), QDir::currentPath(), "PNG File (*.png);;JPEG File (*.jpg);;");
	if (!filename.isEmpty()) {
		ui->lblLeafTexture->setText(filename);
		ui->openGLWidget->setTextures(QString(ui->lblBranchTexture->text()), QString(ui->lblLeafTexture->text()));
	}
}

void wndMain::isShadow(bool shadow)
{
	ui->openGLWidget->setShadow(shadow);
}

void wndMain::isAnimation(bool anim)
{
	ui->openGLWidget->setAnimation(anim);
}

void wndMain::isWireframe(bool wire)
{
	ui->openGLWidget->setWireframe(wire);
}

void wndMain::generate()
{

	QString axiom = ui->txtAxiom->text();
	int iterations = ui->sBoxIterations->value();
	float angle = ui->sBoxAngle->value();
	float approximation = ui->sBoxCylinder->value();
	int hermitesteps = ui->sBoxHermite->value();
	float hermitetangent = ui->sBoxTangent->value();
	float hermitetangent2 = ui->sBoxTangent2->value();
	float length = ui->sBoxLength->value();
	float thickness =ui->sBoxThickness->value();
	float decreasefactor = ui->sBoxDecrease->value();
	float leafScaleX = ui->sBoxLeafX->value();
	float leafScaleY = ui->sBoxLeafY->value();
	float leafBending = ui->sBoxBending->value();
	float leafDecrease = ui->sBoxDecreaseLeaf->value();
	float mindist = ui->sBoxDist->value();

	std::vector<SRules> rules;
	for (int i = 0; i < ui->tableWidget->rowCount(); i++) {

		QTableWidgetItem *rule = ui->tableWidget->item(i, 0);
		QTableWidgetItem *successor = ui->tableWidget->item(i, 1);
		QTableWidgetItem *chance = ui->tableWidget->item(i, 2);
		rules.push_back(SRules(rule->text().toStdString()[0], successor->text().toStdString(), chance->text().toFloat()));

	}
	Logger::getInstance()->write("Start to Generate...");
	ui->openGLWidget->generate(rules, axiom.toStdString(), iterations, angle, length, thickness, decreasefactor, leafScaleX, leafScaleY, leafBending, leafDecrease, hermitetangent, hermitetangent2, hermitesteps, approximation, mindist);
	
}
