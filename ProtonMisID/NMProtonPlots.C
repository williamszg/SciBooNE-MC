{

//###############################################|
//###   Rein-Sehgal Files for Neutrino Mode   ###|
//###############################################|
TFile *f1 = new TFile("../ROOTFILES/protonRS.root");

TH2D *hTotalProton2DRS = (TH2D*)f1->Get("Total2D");
TH1D *hTotalEnergyRS = (TH1D*)f1->Get("TotalE");
TH1D *hTotalMomentumRS = (TH1D*)f1->Get("TotalM");
TH1D *hTotalAngleRS = (TH1D*)f1->Get("TotalA");

TH2D *hSNSProton2DRS = (TH2D*)f1->Get("SNS2D");
TH1D *hSNSEnergyRS = (TH1D*)f1->Get("SNSE");
TH1D *hSNSMomentumRS = (TH1D*)f1->Get("SNSM");
TH1D *hSNSAngleRS = (TH1D*)f1->Get("SNSA");

hTotalEnergyRS->Sumw2();
hTotalMomentumRS->Sumw2();
hTotalAngleRS->Sumw2();
hSNSEnergyRS->Sumw2();
hSNSMomentumRS->Sumw2();
hSNSAngleRS->Sumw2();

//--- Defining the Ratio Histograms ---|
TH2D *Ratio2DRS = new TH2D("Ratio2DRS", "2D Efficiencies", 36, 0, 180, 55, 0, 5500);
TH1D *RatioEnergyRS = new TH1D("RatioEnergyRS", "Energy Efficiencies", 55, 0, 5500);
TH1D *RatioMomentumRS = new TH1D("RatioMomentumRS", "Momentum Efficiencies", 55, 0, 5500);
TH1D *RatioAngleRS = new TH1D("RatioAngleRS", "Angle Efficiencies", 60, 0, 180);

//--- Formatting the Plot
Ratio2DRS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
Ratio2DRS->GetXaxis()->CenterTitle();
Ratio2DRS->GetYaxis()->SetTitle("Proton Momentum (MeV)");
Ratio2DRS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioEnergyRS->GetXaxis()->SetTitle("Proton Energy (MeV)");
RatioEnergyRS->GetXaxis()->CenterTitle();
RatioEnergyRS->GetYaxis()->SetTitle("Efficiency");
RatioEnergyRS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioMomentumRS->GetXaxis()->SetTitle("Proton Momentum (MeV)");
RatioMomentumRS->GetXaxis()->CenterTitle();
RatioMomentumRS->GetYaxis()->SetTitle("Efficiency");
RatioMomentumRS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioAngleRS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
RatioAngleRS->GetXaxis()->CenterTitle();
RatioAngleRS->GetYaxis()->SetTitle("Efficiency");
RatioAngleRS->GetYaxis()->CenterTitle();

Ratio2DRS->Divide(hSNSProton2DRS, hTotalProton2DRS);
RatioEnergyRS->Divide(hSNSEnergyRS, hTotalEnergyRS);
RatioMomentumRS->Divide(hSNSMomentumRS, hTotalMomentumRS);
RatioAngleRS->Divide(hSNSAngleRS, hTotalAngleRS);
//###############################################|


//###############################################|
//###  Berger-Sehgal Files for Neutrino Mode  ###|
//###############################################|
TFile *f2 = new TFile("../ROOTFILES/protonBS.root");

TH2D *hTotalProton2DBS = (TH2D*)f2->Get("Total2D");
TH1D *hTotalEnergyBS = (TH1D*)f2->Get("TotalE");
TH1D *hTotalMomentumBS = (TH1D*)f2->Get("TotalM");
TH1D *hTotalAngleBS = (TH1D*)f2->Get("TotalA");

TH2D *hSNSProton2DBS = (TH2D*)f2->Get("SNS2D");
TH1D *hSNSEnergyBS = (TH1D*)f2->Get("SNSE");
TH1D *hSNSMomentumBS = (TH1D*)f2->Get("SNSM");
TH1D *hSNSAngleBS = (TH1D*)f2->Get("SNSA");

hTotalEnergyBS->Sumw2();
hTotalMomentumBS->Sumw2();
hTotalAngleBS->Sumw2();
hSNSEnergyBS->Sumw2();
hSNSMomentumBS->Sumw2();
hSNSAngleBS->Sumw2();

//--- Defining the Ratio Histograms ---|
TH2D *Ratio2DBS = new TH2D("Ratio2DBS", "2D Efficiencies", 36, 0, 180, 55, 0, 5500);
TH1D *RatioEnergyBS = new TH1D("RatioEnergyBS", "Energy Efficiencies", 55, 0, 5500);
TH1D *RatioMomentumBS = new TH1D("RatioMomentumBS", "Momentum Efficiencies", 55, 0, 5500);
TH1D *RatioAngleBS = new TH1D("RatioAngleBS", "Angle Efficiencies", 60, 0, 180);

//--- Formatting the Plot
Ratio2DBS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
Ratio2DBS->GetXaxis()->CenterTitle();
Ratio2DBS->GetYaxis()->SetTitle("Proton Momentum (MeV)");
Ratio2DBS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioEnergyBS->GetXaxis()->SetTitle("Proton Energy (MeV)");
RatioEnergyBS->GetXaxis()->CenterTitle();
RatioEnergyBS->GetYaxis()->SetTitle("Efficiency");
RatioEnergyBS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioMomentumBS->GetXaxis()->SetTitle("Proton Momentum (MeV)");
RatioMomentumBS->GetXaxis()->CenterTitle();
RatioMomentumBS->GetYaxis()->SetTitle("Efficiency");
RatioMomentumBS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioAngleBS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
RatioAngleBS->GetXaxis()->CenterTitle();
RatioAngleBS->GetYaxis()->SetTitle("Efficiency");
RatioAngleBS->GetYaxis()->CenterTitle();

Ratio2DBS->Divide(hSNSProton2DBS, hTotalProton2DBS);
RatioEnergyBS->Divide(hSNSEnergyBS, hTotalEnergyBS);
RatioMomentumBS->Divide(hSNSMomentumBS, hTotalMomentumBS);
RatioAngleBS->Divide(hSNSAngleBS, hTotalAngleBS);
//###############################################|


//###############################################|
//### Old Rein-Sehgal Files for Neutrino Mode ###|
//###############################################|
TFile *f3 = new TFile("../ROOTFILES/protonORS.root");

TH2D *hTotalProton2DORS = (TH2D*)f3->Get("Total2D");
TH1D *hTotalEnergyORS = (TH1D*)f3->Get("TotalE");
TH1D *hTotalMomentumORS = (TH1D*)f3->Get("TotalM");
TH1D *hTotalAngleORS = (TH1D*)f3->Get("TotalA");

TH2D *hSNSProton2DORS = (TH2D*)f3->Get("SNS2D");
TH1D *hSNSEnergyORS = (TH1D*)f3->Get("SNSE");
TH1D *hSNSMomentumORS = (TH1D*)f3->Get("SNSM");
TH1D *hSNSAngleORS = (TH1D*)f3->Get("SNSA");

hTotalEnergyORS->Sumw2();
hTotalMomentumORS->Sumw2();
hTotalAngleORS->Sumw2();
hSNSEnergyORS->Sumw2();
hSNSMomentumORS->Sumw2();
hSNSAngleORS->Sumw2();

//--- Defining the Ratio Histograms ---|
TH2D *Ratio2DORS = new TH2D("Ratio2DORS", "2D Efficiencies", 36, 0, 180, 55, 0, 5500);
TH1D *RatioEnergyORS = new TH1D("RatioEnergyORS", "Energy Efficiencies", 55, 0, 5500);
TH1D *RatioMomentumORS = new TH1D("RatioMomentumORS", "Momentum Efficiencies", 55, 0, 5500);
TH1D *RatioAngleORS = new TH1D("RatioAngleORS", "Angle Efficiencies", 60, 0, 180);

//--- Formatting the Plot
Ratio2DORS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
Ratio2DORS->GetXaxis()->CenterTitle();
Ratio2DORS->GetYaxis()->SetTitle("Proton Momentum (MeV)");
Ratio2DORS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioEnergyORS->GetXaxis()->SetTitle("Proton Energy (MeV)");
RatioEnergyORS->GetXaxis()->CenterTitle();
RatioEnergyORS->GetYaxis()->SetTitle("Efficiency");
RatioEnergyORS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioMomentumORS->GetXaxis()->SetTitle("Proton Momentum (MeV)");
RatioMomentumORS->GetXaxis()->CenterTitle();
RatioMomentumORS->GetYaxis()->SetTitle("Efficiency");
RatioMomentumORS->GetYaxis()->CenterTitle();

//--- Formatting the Plot
RatioAngleORS->GetXaxis()->SetTitle("Proton Angle (Degrees)");
RatioAngleORS->GetXaxis()->CenterTitle();
RatioAngleORS->GetYaxis()->SetTitle("Efficiency");
RatioAngleORS->GetYaxis()->CenterTitle();

Ratio2DORS->Divide(hSNSProton2DORS, hTotalProton2DORS);
RatioEnergyORS->Divide(hSNSEnergyORS, hTotalEnergyORS);
RatioMomentumORS->Divide(hSNSMomentumORS, hTotalMomentumORS);
RatioAngleORS->Divide(hSNSAngleORS, hTotalAngleORS);
//###############################################|

TFile *TAcceptanceInfo = new TFile("../ROOTFILES/2DProtonAcceptancesNM.root", "RECREATE");

Ratio2DRS->Write();
Ratio2DBS->Write();
Ratio2DORS->Write();

}
