{
// ####################
// # Read in the Data #
// ####################

// =======================================================================================
//                     ### Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBS.root"); //Load Total Muon Info File

TH1D *hTotalPNewBS = (TH1D*)f1->Get("CCTMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewBS = (TH1D*)f1->Get("CCTGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewBS = (TH1D*)f1->Get("CCTMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewBS = (TH1D*)f1->Get("CCTGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hGoodStoppedPNewBS = (TH1D*)f1->Get("GMuonMomS_1"); //Make a clone of the h6 histogram from the BergerSegal.C file for the good stopped muon momentum
TH1D *hGoodStoppedCosNewBS = (TH1D*)f1->Get("GMuonCosS_1"); //Make a clone of the h8 histogram from the BergerSegal.C file for the good stopped muon angle

TH1D *hGoodNonStoppedPNewBS = (TH1D*)f1->Get("GMuonMomNS_1"); //Make a clone of the h9 histogram from the BergerSegal.C file for the good nonstopped muon momentum
TH1D *hGoodNonStoppedCosNewBS = (TH1D*)f1->Get("GMuonCosNS_1"); //Make a clone of the h10 histogram from the BergerSegal.C file for the good nonstopped muon angle

TH1D *hTotalPNewBSCC = (TH1D*)f1->Get("CCTMuonMom_1"); //Make a clone of the h13 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewBSCC = (TH1D*)f1->Get("CCTGMuonMom_1"); //Make a clone of the h19 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewBSCC = (TH1D*)f1->Get("CCTMuonCos_1"); //Make a clone of the h14 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewBSCC = (TH1D*)f1->Get("CCTGMuonCos_1"); //Make a clone of the h20 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hPionEnergyBS = (TH1D*)f1->Get("TPionEnergy");
TH1D *hPionMomentumBS = (TH1D*)f1->Get("TPionMom");
TH1D *hPionAngleBS = (TH1D*)f1->Get("TPionAngle");

TH1D *hPionEnergyGoodBS = (TH1D*)f1->Get("GPionEnergy");
TH1D *hPionMomentumGoodBS = (TH1D*)f1->Get("GPionMom");
TH1D *hPionAngleGoodBS = (TH1D*)f1->Get("GPionAngle");

TH1D *hPionEnergyStoppedBS = (TH1D*)f1->Get("SPionEnergy");
TH1D *hPionMomentumStoppedBS = (TH1D*)f1->Get("SPionMom");
TH1D *hPionAngleStoppedBS = (TH1D*)f1->Get("SPionAngle");

TH1D *hPionEnergyNonStoppedBS = (TH1D*)f1->Get("NSPionEnergy");
TH1D *hPionMomentumNonStoppedBS = (TH1D*)f1->Get("NSPionMom");
TH1D *hPionAngleNonStoppedBS = (TH1D*)f1->Get("NSPionAngle");

TH1D *hPStoppedBSCC = (TH1D*)f1->Get("CCGMuonMomS_1");
TH1D *hCosStoppedBSCC = (TH1D*)f1->Get("CCGMuonCosS_1");
TH1D *hPNonStoppedBSCC = (TH1D*)f1->Get("CCGMuonMomNS_1");
TH1D *hCosNonStoppedBSCC = (TH1D*)f1->Get("CCGMuonCosNS_1");

TH2D *hTotalRatioBS = (TH2D*)f1->Get("T2D_1"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioBS = (TH2D*)f1->Get("G2D_1"); //Make a clone of the h22 histogram from the file

TH2D *hTotalRatioBSCC = (TH2D*)f1->Get("T2D_2"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioBSCC = (TH2D*)f1->Get("G2D_2"); //Make a clone of the h22 histogram from the file


hTotalPNewBS->Sumw2();
hTotalGoodPNewBS->Sumw2();
hTotalCosNewBS->Sumw2();
hTotalGoodCosNewBS->Sumw2();
hGoodStoppedPNewBS->Sumw2();
hGoodStoppedCosNewBS->Sumw2();
hGoodNonStoppedPNewBS->Sumw2();
hGoodNonStoppedCosNewBS->Sumw2();
hTotalPNewBSCC->Sumw2();
hTotalGoodPNewBSCC->Sumw2();
hTotalCosNewBSCC->Sumw2();
hTotalGoodCosNewBSCC->Sumw2();
hPionEnergyBS->Sumw2();
hPionMomentumBS->Sumw2();
hPionAngleBS->Sumw2();
hPionEnergyGoodBS->Sumw2();
hPionMomentumGoodBS->Sumw2();
hPionAngleGoodBS->Sumw2();
hPionEnergyStoppedBS->Sumw2();
hPionMomentumStoppedBS->Sumw2();
hPionAngleStoppedBS->Sumw2();
hPionEnergyNonStoppedBS->Sumw2();
hPionMomentumNonStoppedBS->Sumw2();
hPionAngleNonStoppedBS->Sumw2();
hPStoppedBSCC->Sumw2();
hPNonStoppedBSCC->Sumw2();
hCosStoppedBSCC->Sumw2();
hCosNonStoppedBSCC->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPBS = new TH1D("RatioPBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCBS = new TH1D("RatioCBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioSPBS = new TH1D("RatioSPBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioSCBS = new TH1D("RatioSCBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioNSPBS = new TH1D("RatioNSPBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioNSCBS = new TH1D("RatioNSCBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPBSCC = new TH1D("RatioPBSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCBSCC = new TH1D("RatioCBSCC", "Efficiencies for Angles", 40, 0, 180);
TH1D *PionEnergyRatioBS = new TH1D("PionEnergyRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioBS = new TH1D("PionMomentumRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioBS = new TH1D("PionAngleRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioSBS = new TH1D("PionEnergyRatioSBS", "Pion Efficiencies for Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioSBS = new TH1D("PionMomentumRatioSBS", "Pion Efficiencies for Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioSBS = new TH1D("PionAngleRatioSBS", "Pion Efficiencies for Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioNSBS = new TH1D("PionEnergyRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioNSBS = new TH1D("PionMomentumRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioNSBS = new TH1D("PionAngleRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Angle", 40, 0, 180);
TH2D *Ratio2DBS = new TH2D("Ratio2DBS", "2D Efficiencies", 36, 0, 180, 20, 0, 2000);
TH2D *Ratio2DBSCC = new TH2D("Ratio2DBSCC", "2D Efficiencies for CC Inclusive", 36, 0, 180, 20, 0, 2000);

// ### Formatting the plot ###
PionEnergyRatioBS->SetLineColor(kRed);
PionEnergyRatioBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioBS->GetXaxis()->CenterTitle();
PionEnergyRatioBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioBS->SetLineColor(kRed);
PionMomentumRatioBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioBS->GetXaxis()->CenterTitle();
PionMomentumRatioBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioBS->SetLineColor(kRed);
PionAngleRatioBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioBS->GetXaxis()->CenterTitle();
PionAngleRatioBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioSBS->SetLineColor(kRed);
PionEnergyRatioSBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioSBS->GetXaxis()->CenterTitle();
PionEnergyRatioSBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioSBS->SetLineColor(kRed);
PionMomentumRatioSBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioSBS->GetXaxis()->CenterTitle();
PionMomentumRatioSBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioSBS->SetLineColor(kRed);
PionAngleRatioSBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioSBS->GetXaxis()->CenterTitle();
PionAngleRatioSBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioNSBS->SetLineColor(kRed);
PionEnergyRatioNSBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioNSBS->GetXaxis()->CenterTitle();
PionEnergyRatioNSBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioNSBS->SetLineColor(kRed);
PionMomentumRatioNSBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioNSBS->GetXaxis()->CenterTitle();
PionMomentumRatioNSBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioNSBS->SetLineColor(kRed);
PionAngleRatioNSBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioNSBS->GetXaxis()->CenterTitle();
PionAngleRatioNSBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPBS->SetLineColor(kRed);
RatioPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBS->GetXaxis()->CenterTitle();
RatioPBS->GetYaxis()->SetTitle("Efficiency");
RatioPBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCBS->SetLineColor(kRed);
RatioCBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCBS->GetXaxis()->CenterTitle();
RatioCBS->GetYaxis()->SetTitle("Efficiency");
RatioCBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSPBS->SetLineColor(kRed);
RatioSPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioSPBS->GetXaxis()->CenterTitle();
RatioSPBS->GetYaxis()->SetTitle("Efficiency");
RatioSPBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSCBS->SetLineColor(kRed);
RatioSCBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioSCBS->GetXaxis()->CenterTitle();
RatioSCBS->GetYaxis()->SetTitle("Efficiency");
RatioSCBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSPBS->SetLineColor(kBlue);
RatioNSPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioNSPBS->GetXaxis()->CenterTitle();
RatioNSPBS->GetYaxis()->SetTitle("Efficiency");
RatioNSPBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSCBS->SetLineColor(kBlue);
RatioNSCBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioNSCBS->GetXaxis()->CenterTitle();
RatioNSCBS->GetYaxis()->SetTitle("Efficiency");
RatioNSCBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPBSCC->SetLineColor(kRed);
RatioPBSCC->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBSCC->GetXaxis()->CenterTitle();
RatioPBSCC->GetYaxis()->SetTitle("Efficiency");
RatioPBSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCBSCC->SetLineColor(kRed);
RatioCBSCC->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCBSCC->GetXaxis()->CenterTitle();
RatioCBSCC->GetYaxis()->SetTitle("Efficiency");
RatioCBSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
Ratio2DBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
Ratio2DBS->GetXaxis()->CenterTitle();
Ratio2DBS->GetYaxis()->SetTitle("Muon Momentum (MeV)");
Ratio2DBS->GetYaxis()->CenterTitle();


RatioPBS->Divide(hTotalGoodPNewBS, hTotalPNewBS);
RatioCBS->Divide(hTotalGoodCosNewBS, hTotalCosNewBS);
RatioSPBS->Divide(hPStoppedBSCC, hTotalGoodPNewBSCC);
RatioSCBS->Divide(hCosStoppedBSCC, hTotalGoodCosNewBSCC);
RatioNSPBS->Divide(hPNonStoppedBSCC, hTotalGoodPNewBSCC);
RatioNSCBS->Divide(hCosNonStoppedBSCC, hTotalGoodCosNewBSCC);
RatioPBSCC->Divide(hTotalGoodPNewBSCC, hTotalPNewBSCC);
RatioCBSCC->Divide(hTotalGoodCosNewBSCC, hTotalCosNewBSCC);
PionEnergyRatioBS->Divide(hPionEnergyGoodBS, hPionEnergyBS);
PionMomentumRatioBS->Divide(hPionMomentumGoodBS, hPionMomentumBS);
PionAngleRatioBS->Divide(hPionAngleGoodBS, hPionAngleBS);
PionEnergyRatioSBS->Divide(hPionEnergyStoppedBS, hPionEnergyGoodBS);
PionMomentumRatioSBS->Divide(hPionMomentumStoppedBS, hPionMomentumGoodBS);
PionAngleRatioSBS->Divide(hPionAngleStoppedBS, hPionAngleGoodBS);
PionEnergyRatioNSBS->Divide(hPionEnergyNonStoppedBS, hPionEnergyGoodBS);
PionMomentumRatioNSBS->Divide(hPionMomentumNonStoppedBS, hPionMomentumGoodBS);
PionAngleRatioNSBS->Divide(hPionAngleNonStoppedBS, hPionAngleGoodBS);
Ratio2DBS->Divide(hGoodRatioBS, hTotalRatioBS);
Ratio2DBSCC->Divide(hGoodRatioBSCC, hTotalRatioBSCC);




// =======================================================================================
//                    ### Rein Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f2 = new TFile("./ROOTFILES/totalmuoninfoRS.root"); //Load Total Muon Info File

TH1D *hTotalPNewRS = (TH1D*)f2->Get("CCTMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRS = (TH1D*)f2->Get("CCTGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRS = (TH1D*)f2->Get("CCTMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRS = (TH1D*)f2->Get("CCTGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hGoodStoppedPNewRS = (TH1D*)f2->Get("GMuonMomS_1"); //Make a clone of the h6 histogram from the BergerSegal.C file for the good stopped muon momentum
TH1D *hGoodStoppedCosNewRS = (TH1D*)f2->Get("GMuonCosS_1"); //Make a clone of the h8 histogram from the BergerSegal.C file for the good stopped muon angle

TH1D *hGoodNonStoppedPNewRS = (TH1D*)f2->Get("GMuonMomNS_1"); //Make a clone of the h9 histogram from the BergerSegal.C file for the good nonstopped muon momentum
TH1D *hGoodNonStoppedCosNewRS = (TH1D*)f2->Get("GMuonCosNS_1"); //Make a clone of the h10 histogram from the BergerSegal.C file for the good nonstopped muon angle

TH1D *hTotalPNewRSCC = (TH1D*)f2->Get("CCTMuonMom_1"); //Make a clone of the h13 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRSCC = (TH1D*)f2->Get("CCTGMuonMom_1"); //Make a clone of the h19 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRSCC = (TH1D*)f2->Get("CCTMuonCos_1"); //Make a clone of the h14 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRSCC = (TH1D*)f2->Get("CCTGMuonCos_1"); //Make a clone of the h20 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hPionEnergyRS = (TH1D*)f2->Get("TPionEnergy");
TH1D *hPionMomentumRS = (TH1D*)f2->Get("TPionMom");
TH1D *hPionAngleRS = (TH1D*)f2->Get("TPionAngle");

TH1D *hPionEnergyGoodRS = (TH1D*)f2->Get("GPionEnergy");
TH1D *hPionMomentumGoodRS = (TH1D*)f2->Get("GPionMom");
TH1D *hPionAngleGoodRS = (TH1D*)f2->Get("GPionAngle");

TH1D *hPionEnergyStoppedRS = (TH1D*)f2->Get("SPionEnergy");
TH1D *hPionMomentumStoppedRS = (TH1D*)f2->Get("SPionMom");
TH1D *hPionAngleStoppedRS = (TH1D*)f2->Get("SPionAngle");

TH1D *hPionEnergyNonStoppedRS = (TH1D*)f2->Get("NSPionEnergy");
TH1D *hPionMomentumNonStoppedRS = (TH1D*)f2->Get("NSPionMom");
TH1D *hPionAngleNonStoppedRS = (TH1D*)f2->Get("NSPionAngle");

TH2D *hTotalRatioRS = (TH2D*)f2->Get("T2D_1"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioRS = (TH2D*)f2->Get("G2D_1"); //Make a clone of the h22 histogram from the file

TH2D *hTotalRatioRSCC = (TH2D*)f2->Get("T2D_2"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioRSCC = (TH2D*)f2->Get("G2D_2"); //Make a clone of the h22 histogram from the file


hTotalPNewRS->Sumw2();
hTotalGoodPNewRS->Sumw2();
hTotalCosNewRS->Sumw2();
hTotalGoodCosNewRS->Sumw2();
hGoodStoppedPNewRS->Sumw2();
hGoodStoppedCosNewRS->Sumw2();
hGoodNonStoppedPNewRS->Sumw2();
hGoodNonStoppedCosNewRS->Sumw2();
hTotalPNewRSCC->Sumw2();
hTotalGoodPNewRSCC->Sumw2();
hTotalCosNewRSCC->Sumw2();
hTotalGoodCosNewRSCC->Sumw2();
hPionEnergyRS->Sumw2();
hPionMomentumRS->Sumw2();
hPionAngleRS->Sumw2();
hPionEnergyGoodRS->Sumw2();
hPionMomentumGoodRS->Sumw2();
hPionAngleGoodRS->Sumw2();
hPionEnergyStoppedRS->Sumw2();
hPionMomentumStoppedRS->Sumw2();
hPionAngleStoppedRS->Sumw2();
hPionEnergyNonStoppedRS->Sumw2();
hPionMomentumNonStoppedRS->Sumw2();
hPionAngleNonStoppedRS->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPRS = new TH1D("RatioPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRS = new TH1D("RatioCRS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioSPRS = new TH1D("RatioSPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioSCRS = new TH1D("RatioSCRS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioNSPRS = new TH1D("RatioNSPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioNSCRS = new TH1D("RatioNSCRS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPRSCC = new TH1D("RatioPRSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRSCC = new TH1D("RatioCRSCC", "Efficiencies for Angles", 40, 0, 180);
TH1D *PionEnergyRatioRS = new TH1D("PionEnergyRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioRS = new TH1D("PionMomentumRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioRS = new TH1D("PionAngleRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioSRS = new TH1D("PionEnergyRatioSRS", "Pion Efficiencies for Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioSRS = new TH1D("PionMomentumRatioSRS", "Pion Efficiencies for Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioSRS = new TH1D("PionAngleRatioSRS", "Pion Efficiencies for Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioNSRS = new TH1D("PionEnergyRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioNSRS = new TH1D("PionMomentumRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioNSRS = new TH1D("PionAngleRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Angle", 40, 0, 180);
TH2D *Ratio2DRS = new TH2D("Ratio2DRS", "2D Efficiencies", 36, 0, 180, 20, 0, 2000);
TH2D *Ratio2DRSCC = new TH2D("Ratio2DRSCC", "2D Efficiencies for CC Inclusive", 36, 0, 180, 20, 0, 2000);

// ### Formatting the plot ###
PionEnergyRatioRS->SetLineColor(kBlue);
PionEnergyRatioRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioRS->GetXaxis()->CenterTitle();
PionEnergyRatioRS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioRS->SetLineColor(kBlue);
PionMomentumRatioRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioRS->GetXaxis()->CenterTitle();
PionMomentumRatioRS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioRS->SetLineColor(kBlue);
PionAngleRatioRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioRS->GetXaxis()->CenterTitle();
PionAngleRatioRS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioSRS->SetLineColor(kBlue);
PionEnergyRatioSRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioSRS->GetXaxis()->CenterTitle();
PionEnergyRatioSRS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioSRS->SetLineColor(kBlue);
PionMomentumRatioSRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioSRS->GetXaxis()->CenterTitle();
PionMomentumRatioSRS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioSRS->SetLineColor(kBlue);
PionAngleRatioSRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioSRS->GetXaxis()->CenterTitle();
PionAngleRatioSRS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioNSRS->SetLineColor(kBlue);
PionEnergyRatioNSRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioNSRS->GetXaxis()->CenterTitle();
PionEnergyRatioNSRS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioNSRS->SetLineColor(kBlue);
PionMomentumRatioNSRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioNSRS->GetXaxis()->CenterTitle();
PionMomentumRatioNSRS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioNSRS->SetLineColor(kBlue);
PionAngleRatioNSRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioNSRS->GetXaxis()->CenterTitle();
PionAngleRatioNSRS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPRS->SetLineColor(kBlue);
RatioPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRS->GetXaxis()->CenterTitle();
RatioPRS->GetYaxis()->SetTitle("Efficiency");
RatioPRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCRS->SetLineColor(kBlue);
RatioCRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCRS->GetXaxis()->CenterTitle();
RatioCRS->GetYaxis()->SetTitle("Efficiency");
RatioCRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSPRS->SetLineColor(kRed);
RatioSPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioSPRS->GetXaxis()->CenterTitle();
RatioSPRS->GetYaxis()->SetTitle("Efficiency");
RatioSPRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSCRS->SetLineColor(kRed);
RatioSCRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioSCRS->GetXaxis()->CenterTitle();
RatioSCRS->GetYaxis()->SetTitle("Efficiency");
RatioSCRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSPRS->SetLineColor(kBlue);
RatioNSPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioNSPRS->GetXaxis()->CenterTitle();
RatioNSPRS->GetYaxis()->SetTitle("Efficiency");
RatioNSPRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSCRS->SetLineColor(kBlue);
RatioNSCRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioNSCRS->GetXaxis()->CenterTitle();
RatioNSCRS->GetYaxis()->SetTitle("Efficiency");
RatioNSCRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPRSCC->SetLineColor(kBlue);
RatioPRSCC->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRSCC->GetXaxis()->CenterTitle();
RatioPRSCC->GetYaxis()->SetTitle("Efficiency");
RatioPRSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCRSCC->SetLineColor(kBlue);
RatioCRSCC->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCRSCC->GetXaxis()->CenterTitle();
RatioCRSCC->GetYaxis()->SetTitle("Efficiency");
RatioCRSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
Ratio2DRS->GetYaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
Ratio2DRS->GetYaxis()->CenterTitle();
Ratio2DRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
Ratio2DRS->GetXaxis()->CenterTitle();


RatioPRS->Divide(hTotalGoodPNewRS, hTotalPNewRS);
RatioCRS->Divide(hTotalGoodCosNewRS, hTotalCosNewRS);
RatioSPRS->Divide(hGoodStoppedPNewRS, hTotalPNewRS);
RatioSCRS->Divide(hGoodStoppedCosNewRS, hTotalCosNewRS);
RatioNSPRS->Divide(hGoodNonStoppedPNewRS, hTotalPNewRS);
RatioNSCRS->Divide(hGoodNonStoppedCosNewRS, hTotalCosNewRS);
RatioPRSCC->Divide(hTotalGoodPNewRSCC, hTotalPNewRSCC);
RatioCRSCC->Divide(hTotalGoodCosNewRSCC, hTotalCosNewRSCC);
PionEnergyRatioRS->Divide(hPionEnergyGoodRS, hPionEnergyRS);
PionMomentumRatioRS->Divide(hPionMomentumGoodRS, hPionMomentumRS);
PionAngleRatioRS->Divide(hPionAngleGoodRS, hPionAngleRS);
PionEnergyRatioSRS->Divide(hPionEnergyStoppedRS, hPionEnergyGoodRS);
PionMomentumRatioSRS->Divide(hPionMomentumStoppedRS, hPionMomentumGoodRS);
PionAngleRatioSRS->Divide(hPionAngleStoppedRS, hPionAngleGoodRS);
PionEnergyRatioNSRS->Divide(hPionEnergyNonStoppedRS, hPionEnergyGoodRS);
PionMomentumRatioNSRS->Divide(hPionMomentumNonStoppedRS, hPionMomentumGoodRS);
PionAngleRatioNSRS->Divide(hPionAngleNonStoppedRS, hPionAngleGoodRS);
Ratio2DRS->Divide(hGoodRatioRS, hTotalRatioRS);
Ratio2DRSCC->Divide(hGoodRatioRSCC, hTotalRatioRSCC);




// =======================================================================================
//                  ### Old Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f3 = new TFile("./ROOTFILES/totalmuoninfoOBS.root"); //Load Total Muon Info File

TH1D *hTotalPNewOBS = (TH1D*)f3->Get("CCTMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewOBS = (TH1D*)f3->Get("CCTGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewOBS = (TH1D*)f3->Get("CCTMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewOBS = (TH1D*)f3->Get("CCTGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hGoodStoppedPNewOBS = (TH1D*)f3->Get("GMuonMomS_1"); //Make a clone of the h6 histogram from the BergerSegal.C file for the good stopped muon momentum
TH1D *hGoodStoppedCosNewOBS = (TH1D*)f3->Get("GMuonCosS_1"); //Make a clone of the h8 histogram from the BergerSegal.C file for the good stopped muon angle

TH1D *hGoodNonStoppedPNewOBS = (TH1D*)f3->Get("GMuonMomNS_1"); //Make a clone of the h9 histogram from the BergerSegal.C file for the good nonstopped muon momentum
TH1D *hGoodNonStoppedCosNewOBS = (TH1D*)f3->Get("GMuonCosNS_1"); //Make a clone of the h10 histogram from the BergerSegal.C file for the good nonstopped muon angle

TH1D *hTotalPNewOBSCC = (TH1D*)f3->Get("CCTMuonMom_1"); //Make a clone of the h13 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewOBSCC = (TH1D*)f3->Get("CCTGMuonMom_1"); //Make a clone of the h19 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewOBSCC = (TH1D*)f3->Get("CCTMuonCos_1"); //Make a clone of the h14 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewOBSCC = (TH1D*)f3->Get("CCTGMuonCos_1"); //Make a clone of the h20 histogram from the NeutrinoMode.C file for total good muon angle

TH1D *hPionEnergyOBS = (TH1D*)f3->Get("TPionEnergy");
TH1D *hPionMomentumOBS = (TH1D*)f3->Get("TPionMom");
TH1D *hPionAngleOBS = (TH1D*)f3->Get("TPionAngle");

TH1D *hPionEnergyGoodOBS = (TH1D*)f3->Get("GPionEnergy");
TH1D *hPionMomentumGoodOBS = (TH1D*)f3->Get("GPionMom");
TH1D *hPionAngleGoodOBS = (TH1D*)f3->Get("GPionAngle");

TH1D *hPionEnergyStoppedOBS = (TH1D*)f3->Get("SPionEnergy");
TH1D *hPionMomentumStoppedOBS = (TH1D*)f3->Get("SPionMom");
TH1D *hPionAngleStoppedOBS = (TH1D*)f3->Get("SPionAngle");

TH1D *hPionEnergyNonStoppedOBS = (TH1D*)f3->Get("NSPionEnergy");
TH1D *hPionMomentumNonStoppedOBS = (TH1D*)f3->Get("NSPionMom");
TH1D *hPionAngleNonStoppedOBS = (TH1D*)f3->Get("NSPionAngle");

TH2D *hTotalRatioOBS = (TH2D*)f3->Get("T2D_1"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioOBS = (TH2D*)f3->Get("G2D_1"); //Make a clone of the h22 histogram from the file

TH2D *hTotalRatioOBSCC = (TH2D*)f3->Get("T2D_2"); //Make a clone of the h21 histogram from the file
TH2D *hGoodRatioOBSCC = (TH2D*)f3->Get("G2D_2"); //Make a clone of the h22 histogram from the file


hTotalPNewOBS->Sumw2();
hTotalGoodPNewOBS->Sumw2();
hTotalCosNewOBS->Sumw2();
hTotalGoodCosNewOBS->Sumw2();
hGoodStoppedPNewOBS->Sumw2();
hGoodStoppedCosNewOBS->Sumw2();
hGoodNonStoppedPNewOBS->Sumw2();
hGoodNonStoppedCosNewOBS->Sumw2();
hTotalPNewOBSCC->Sumw2();
hTotalGoodPNewOBSCC->Sumw2();
hTotalCosNewOBSCC->Sumw2();
hTotalGoodCosNewOBSCC->Sumw2();
hPionEnergyOBS->Sumw2();
hPionMomentumOBS->Sumw2();
hPionAngleOBS->Sumw2();
hPionEnergyGoodOBS->Sumw2();
hPionMomentumGoodOBS->Sumw2();
hPionAngleGoodOBS->Sumw2();
hPionEnergyStoppedOBS->Sumw2();
hPionMomentumStoppedOBS->Sumw2();
hPionAngleStoppedOBS->Sumw2();
hPionEnergyNonStoppedOBS->Sumw2();
hPionMomentumNonStoppedOBS->Sumw2();
hPionAngleNonStoppedOBS->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPOBS = new TH1D("RatioPOBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCOBS = new TH1D("RatioCOBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioSPOBS = new TH1D("RatioSPOBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioSCOBS = new TH1D("RatioSCOBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioNSPOBS = new TH1D("RatioNSPOBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioNSCOBS = new TH1D("RatioNSCOBS", "Efficiencies for Angles", 40, 0, 180);
TH1D *RatioPOBSCC = new TH1D("RatioPOBSCC", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCOBSCC = new TH1D("RatioCOBSCC", "Efficiencies for Angles", 40, 0, 180);
TH1D *PionEnergyRatioOBS = new TH1D("PionEnergyRatioOBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioOBS = new TH1D("PionMomentumRatioOBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioOBS = new TH1D("PionAngleRatioOBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioSOBS = new TH1D("PionEnergyRatioSOBS", "Pion Efficiencies for Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioSOBS = new TH1D("PionMomentumRatioSOBS", "Pion Efficiencies for Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioSOBS = new TH1D("PionAngleRatioSOBS", "Pion Efficiencies for Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioNSOBS = new TH1D("PionEnergyRatioNSOBS", "Pion Efficiencies for Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioNSOBS = new TH1D("PionMomentumRatioNSOBS", "Pion Efficiencies for Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioNSOBS = new TH1D("PionAngleRatioNSOBS", "Pion Efficiencies for Non-Stopped Muon Angle", 40, 0, 180);
TH2D *Ratio2DOBS = new TH2D("Ratio2DOBS", "2D Efficiencies", 36, 0, 180, 20, 0, 2000);
TH2D *Ratio2DOBSCC = new TH2D("Ratio2DOBSCC", "2D Efficiencies for CC Inclusive", 36, 0, 180, 20, 0, 2000);

// ### Formatting the plot ###
PionEnergyRatioOBS->SetLineColor(kBlack);
PionEnergyRatioOBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioOBS->GetXaxis()->CenterTitle();
PionEnergyRatioOBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioOBS->SetLineColor(kBlack);
PionMomentumRatioOBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioOBS->GetXaxis()->CenterTitle();
PionMomentumRatioOBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioOBS->SetLineColor(kBlack);
PionAngleRatioOBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioOBS->GetXaxis()->CenterTitle();
PionAngleRatioOBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioSOBS->SetLineColor(kBlack);
PionEnergyRatioSOBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioSOBS->GetXaxis()->CenterTitle();
PionEnergyRatioSOBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioSOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioSOBS->SetLineColor(kBlack);
PionMomentumRatioSOBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioSOBS->GetXaxis()->CenterTitle();
PionMomentumRatioSOBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioSOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioSOBS->SetLineColor(kBlack);
PionAngleRatioSOBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioSOBS->GetXaxis()->CenterTitle();
PionAngleRatioSOBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioSOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioNSOBS->SetLineColor(kBlack);
PionEnergyRatioNSOBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioNSOBS->GetXaxis()->CenterTitle();
PionEnergyRatioNSOBS->GetYaxis()->SetTitle("Efficiency");
PionEnergyRatioNSOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioNSOBS->SetLineColor(kBlack);
PionMomentumRatioNSOBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioNSOBS->GetXaxis()->CenterTitle();
PionMomentumRatioNSOBS->GetYaxis()->SetTitle("Efficiency");
PionMomentumRatioNSOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioNSOBS->SetLineColor(kBlack);
PionAngleRatioNSOBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioNSOBS->GetXaxis()->CenterTitle();
PionAngleRatioNSOBS->GetYaxis()->SetTitle("Efficiency");
PionAngleRatioNSOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPOBS->SetLineColor(kBlack);
RatioPOBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPOBS->GetXaxis()->CenterTitle();
RatioPOBS->GetYaxis()->SetTitle("Efficiency");
RatioPOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCOBS->SetLineColor(kBlack);
RatioCOBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCOBS->GetXaxis()->CenterTitle();
RatioCOBS->GetYaxis()->SetTitle("Efficiency");
RatioCOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSPOBS->SetLineColor(kRed);
RatioSPOBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioSPOBS->GetXaxis()->CenterTitle();
RatioSPOBS->GetYaxis()->SetTitle("Efficiency");
RatioSPOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioSCOBS->SetLineColor(kRed);
RatioSCOBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioSCOBS->GetXaxis()->CenterTitle();
RatioSCOBS->GetYaxis()->SetTitle("Efficiency");
RatioSCOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSPOBS->SetLineColor(kBlue);
RatioNSPOBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioNSPOBS->GetXaxis()->CenterTitle();
RatioNSPOBS->GetYaxis()->SetTitle("Efficiency");
RatioNSPOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioNSCOBS->SetLineColor(kBlue);
RatioNSCOBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioNSCOBS->GetXaxis()->CenterTitle();
RatioNSCOBS->GetYaxis()->SetTitle("Efficiency");
RatioNSCOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioPOBSCC->SetLineColor(kBlack);
RatioPOBSCC->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPOBSCC->GetXaxis()->CenterTitle();
RatioPOBSCC->GetYaxis()->SetTitle("Efficiency");
RatioPOBSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCOBSCC->SetLineColor(kBlack);
RatioCOBSCC->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCOBSCC->GetXaxis()->CenterTitle();
RatioCOBSCC->GetYaxis()->SetTitle("Efficiency");
RatioCOBSCC->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
Ratio2DOBS->GetYaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
Ratio2DOBS->GetYaxis()->CenterTitle();
Ratio2DOBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
Ratio2DOBS->GetXaxis()->CenterTitle();


RatioPOBS->Divide(hTotalGoodPNewOBS, hTotalPNewOBS);
RatioCOBS->Divide(hTotalGoodCosNewOBS, hTotalCosNewOBS);
RatioSPOBS->Divide(hGoodStoppedPNewOBS, hTotalPNewOBS);
RatioSCOBS->Divide(hGoodStoppedCosNewOBS, hTotalCosNewOBS);
RatioNSPOBS->Divide(hGoodNonStoppedPNewOBS, hTotalPNewOBS);
RatioNSCOBS->Divide(hGoodNonStoppedCosNewOBS, hTotalCosNewOBS);
RatioPOBSCC->Divide(hTotalGoodPNewOBSCC, hTotalPNewOBSCC);
RatioCOBSCC->Divide(hTotalGoodCosNewOBSCC, hTotalCosNewOBSCC);
PionEnergyRatioOBS->Divide(hPionEnergyGoodOBS, hPionEnergyOBS);
PionMomentumRatioOBS->Divide(hPionMomentumGoodOBS, hPionMomentumOBS);
PionAngleRatioOBS->Divide(hPionAngleGoodOBS, hPionAngleOBS);
PionEnergyRatioSOBS->Divide(hPionEnergyStoppedOBS, hPionEnergyGoodOBS);
PionMomentumRatioSOBS->Divide(hPionMomentumStoppedOBS, hPionMomentumGoodOBS);
PionAngleRatioSOBS->Divide(hPionAngleStoppedOBS, hPionAngleGoodOBS);
PionEnergyRatioNSOBS->Divide(hPionEnergyNonStoppedOBS, hPionEnergyGoodOBS);
PionMomentumRatioNSOBS->Divide(hPionMomentumNonStoppedOBS, hPionMomentumGoodOBS);
PionAngleRatioNSOBS->Divide(hPionAngleNonStoppedOBS, hPionAngleGoodOBS);
Ratio2DOBS->Divide(hGoodRatioOBS, hTotalRatioOBS);
Ratio2DOBSCC->Divide(hGoodRatioOBSCC, hTotalRatioOBSCC);




// =======================================================================================
//                ### Berger Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f4 = new TFile("./ROOTFILES/totalmuoninfoBSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewBSBar = (TH1D*)f4->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewBSBar = (TH1D*)f4->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewBSBar = (TH1D*)f4->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewBSBar = (TH1D*)f4->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle


hTotalPNewBSBar->Sumw2();
hTotalGoodPNewBSBar->Sumw2();
hTotalCosNewBSBar->Sumw2();
hTotalGoodCosNewBSBar->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPBSBar = new TH1D("RatioPBSBar", "Efficiencies for Momentums", 40, 0, 2500);
TH1D *RatioCBSBar = new TH1D("RatioCBSBar", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPBSBar->SetLineColor(kBlack);
RatioPBSBar->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBSBar->GetXaxis()->CenterTitle();
RatioPBSBar->GetYaxis()->SetTitle("Efficiency");
RatioPBSBar->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCBSBar->SetLineColor(kBlack);
RatioCBSBar->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCBSBar->GetXaxis()->CenterTitle();
RatioCBSBar->GetYaxis()->SetTitle("Efficiency");
RatioCBSBar->GetYaxis()->CenterTitle();

RatioPBSBar->Divide(hTotalGoodPNewBSBar, hTotalPNewBSBar);
RatioCBSBar->Divide(hTotalGoodCosNewBSBar, hTotalCosNewBSBar);




// =======================================================================================
//                ### Rein Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f5 = new TFile("./ROOTFILES/totalmuoninfoRSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewRSBar = (TH1D*)f5->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRSBar = (TH1D*)f5->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRSBar = (TH1D*)f5->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRSBar = (TH1D*)f5->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle


hTotalPNewRSBar->Sumw2();
hTotalGoodPNewRSBar->Sumw2();
hTotalCosNewRSBar->Sumw2();
hTotalGoodCosNewRSBar->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPRSBar = new TH1D("RatioPRSBar", "Efficiencies for Momentums", 40, 0, 2500);
TH1D *RatioCRSBar = new TH1D("RatioCRSBar", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPRSBar->SetLineColor(kMagenta);
RatioPRSBar->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRSBar->GetXaxis()->CenterTitle();
RatioPRSBar->GetYaxis()->SetTitle("Efficiency");
RatioPRSBar->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCRSBar->SetLineColor(kMagenta);
RatioCRSBar->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCRSBar->GetXaxis()->CenterTitle();
RatioCRSBar->GetYaxis()->SetTitle("Efficiency");
RatioCRSBar->GetYaxis()->CenterTitle();

RatioPRSBar->Divide(hTotalGoodPNewRSBar, hTotalPNewRSBar);
RatioCRSBar->Divide(hTotalGoodCosNewRSBar, hTotalCosNewRSBar);




// ##############################################
// # Drawing the Momentum Efficiency Histograms #
// ##############################################

TCanvas *c1 = new TCanvas("c1", "Muon Momentums Efficiencies Histogram");
c1->SetTicks();
c1->SetFillColor(kWhite);

RatioPBS->Draw("E1");
RatioPRS->Draw("E1same");
RatioPOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("SciBooNE MC");
leg->AddEntry(RatioPRS,"NEUT v5.3.6 Rein-Sehgal");
leg->AddEntry(RatioPBS,"NEUT v5.3.6 Berger-Sehgal");
leg->AddEntry(RatioPOBS, "NEUT v5.0.1 Rein-Sehgal");
leg->Draw();




// ############################################
// # Drawing the Angles Efficiency Histograms #
// ############################################

TCanvas *c6 = new TCanvas("c6", "Muon Angles Efficiencies Histogram");
c6->SetTicks();
c6->SetFillColor(kWhite);

RatioCBS->Draw("E1");
RatioCRS->Draw("E1same");
RatioCOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg5 = new TLegend();
leg5 = new TLegend(0.58,0.65,0.88,0.88);
leg5->SetTextSize(0.04);
leg5->SetTextAlign(12);
leg5->SetFillColor(kWhite);
leg5->SetLineColor(kWhite);
leg5->SetShadowColor(kWhite);
leg5->SetHeader("SciBooNE MC");
leg5->AddEntry(RatioCRS,"NEUT v5.3.6 Rein-Sehgal");
leg5->AddEntry(RatioCBS,"NEUT v5.3.6 Berger-Sehgal");
leg5->AddEntry(RatioCOBS, "NEUT v5.0.1 Rein-Sehgal");
leg5->Draw();




// #################################################
// # Drawing the CC Momentum Efficiency Histograms #
// #################################################

TCanvas *c11 = new TCanvas("c11", "CC Muon Momentums Efficiencies Histogram");
c11->SetTicks();
c11->SetFillColor(kWhite);

RatioPBSCC->Draw("E1");
RatioPRSCC->Draw("E1same");
RatioPOBSCC->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg10 = new TLegend();
leg10 = new TLegend(0.58,0.65,0.88,0.88);
leg10->SetTextSize(0.04);
leg10->SetTextAlign(12);
leg10->SetFillColor(kWhite);
leg10->SetLineColor(kWhite);
leg10->SetShadowColor(kWhite);
leg10->SetHeader("SciBooNE MC");
leg10->AddEntry(RatioPRSCC,"NEUT v5.3.6 Rein-Sehgal");
leg10->AddEntry(RatioPBSCC,"NEUT v5.3.6 Berger-Sehgal");
leg10->AddEntry(RatioPOBSCC, "NEUT v5.0.1 Rein-Sehgal");
leg10->Draw();




// ###############################################
// # Drawing the CC Angles Efficiency Histograms #
// ###############################################

TCanvas *c12 = new TCanvas("c12", "CC Muon Angles Efficiencies Histogram");
c12->SetTicks();
c12->SetFillColor(kWhite);

RatioCBSCC->Draw("E1");
RatioCRSCC->Draw("E1same");
RatioCOBSCC->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg11 = new TLegend();
leg11 = new TLegend(0.58,0.65,0.88,0.88);
leg11->SetTextSize(0.04);
leg11->SetTextAlign(12);
leg11->SetFillColor(kWhite);
leg11->SetLineColor(kWhite);
leg11->SetShadowColor(kWhite);
leg11->SetHeader("SciBooNE MC");
leg11->AddEntry(RatioCRSCC,"NEUT v5.3.6 Rein-Sehgal");
leg11->AddEntry(RatioCBSCC,"NEUT v5.3.6 Berger-Sehgal");
leg11->AddEntry(RatioCOBSCC, "NEUT v5.0.1 Rein-Sehgal");
leg11->Draw();




// ################################################################
// # Drawing the RS Neut-Anti-Neut Momentum Efficiency Histograms #
// ################################################################

TCanvas *c13 = new TCanvas("c13", "R-S Neut-Anti-Neut Muon Momentums Efficiencies Histogram");
c13->SetTicks();
c13->SetFillColor(kWhite);

RatioPRS->Draw("E1");
RatioPRSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg12 = new TLegend();
leg12 = new TLegend(0.58,0.65,0.88,0.88);
leg12->SetTextSize(0.04);
leg12->SetTextAlign(12);
leg12->SetFillColor(kWhite);
leg12->SetLineColor(kWhite);
leg12->SetShadowColor(kWhite);
leg12->SetHeader("SciBooNE MC");
leg12->AddEntry(RatioPRS,"Neut R-S Model");
leg12->AddEntry(RatioPRSBar,"Anti-Neut R-S Model");
leg12->Draw();




// ##############################################################
// # Drawing the RS Neut-Anti-Neut Angles Efficiency Histograms #
// ##############################################################

TCanvas *c14 = new TCanvas("c14", "R-S Neut-Anti-Neut Muon Angles Efficiencies Histogram");
c14->SetTicks();
c14->SetFillColor(kWhite);

RatioCRS->Draw("E1");
RatioCRSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg13 = new TLegend();
leg13 = new TLegend(0.58,0.65,0.88,0.88);
leg13->SetTextSize(0.04);
leg13->SetTextAlign(12);
leg13->SetFillColor(kWhite);
leg13->SetLineColor(kWhite);
leg13->SetShadowColor(kWhite);
leg13->SetHeader("SciBooNE MC");
leg13->AddEntry(RatioCRS,"Neut R-S Model");
leg13->AddEntry(RatioCRSBar,"Anti-Neut R-S Model");
leg13->Draw();



// ################################################################
// # Drawing the BS Neut-Anti-Neut Momentum Efficiency Histograms #
// ################################################################

TCanvas *c15 = new TCanvas("c15", "B-S Neut-Anti-Neut Muon Momentums Efficiencies Histogram");
c15->SetTicks();
c15->SetFillColor(kWhite);

RatioPBS->Draw("E1");
RatioPBSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg14 = new TLegend();
leg14 = new TLegend(0.58,0.65,0.88,0.88);
leg14->SetTextSize(0.04);
leg14->SetTextAlign(12);
leg14->SetFillColor(kWhite);
leg14->SetLineColor(kWhite);
leg14->SetShadowColor(kWhite);
leg14->SetHeader("SciBooNE MC");
leg14->AddEntry(RatioPBS,"Neut B-S Model");
leg14->AddEntry(RatioPBSBar,"Anti-Neut B-S Model");
leg14->Draw();




// ##############################################################
// # Drawing the BS Neut-Anti-Neut Angles Efficiency Histograms #
// ##############################################################

TCanvas *c16 = new TCanvas("c16", "B-S Neut-Anti-Neut Muon Angles Efficiencies Histogram");
c16->SetTicks();
c16->SetFillColor(kWhite);

RatioCBS->Draw("E1");
RatioCBSBar->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg15 = new TLegend();
leg15 = new TLegend(0.58,0.65,0.88,0.88);
leg15->SetTextSize(0.04);
leg15->SetTextAlign(12);
leg15->SetFillColor(kWhite);
leg15->SetLineColor(kWhite);
leg15->SetShadowColor(kWhite);
leg15->SetHeader("SciBooNE MC");
leg15->AddEntry(RatioCBS,"Neut B-S Model");
leg15->AddEntry(RatioCBSBar,"Anti-Neut B-S Model");
leg15->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c2 = new TCanvas("c2", "Muon Momentums");
c2->SetTicks();
c2->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalPNewRS->Scale(1/hTotalPNewRS->Integral());

hTotalPNewBS->Scale(1/hTotalPNewBS->Integral());

hTotalPNewOBS->Scale(1/hTotalPNewOBS->Integral());

hTotalPNewRS->SetLineColor(kBlue);
hTotalPNewRS->SetLineWidth(2);

hTotalPNewBS->SetLineColor(kRed);
hTotalPNewBS->SetLineWidth(2);

hTotalPNewOBS->SetLineColor(kBlack);
hTotalPNewOBS->SetLineWidth(2);

hTotalPNewOBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hTotalPNewOBS->GetXaxis()->CenterTitle();

hTotalPNewOBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hTotalPNewOBS->GetYaxis()->CenterTitle();

hTotalPNewOBS->Draw("histo");
hTotalPNewRS->Draw("histosame");
hTotalPNewBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg1 = new TLegend();
leg1 = new TLegend(0.58,0.65,0.88,0.88);
leg1->SetTextSize(0.04);
leg1->SetTextAlign(12);
leg1->SetFillColor(kWhite);
leg1->SetLineColor(kWhite);
leg1->SetShadowColor(kWhite);
leg1->SetHeader("SciBooNE MC");
leg1->AddEntry(hTotalPNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg1->AddEntry(hTotalPNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg1->AddEntry(hTotalPNewOBS, "NEUT v5.0.1 Rein-Sehgal");
leg1->Draw();




// #################################
// # Drawing the Cosine Histograms #
// #################################

TCanvas *c3 = new TCanvas("c3", "Muon Angles");
c3->SetTicks();
c3->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalCosNewRS->Scale(1/hTotalCosNewRS->Integral());

hTotalCosNewBS->Scale(1/hTotalCosNewBS->Integral());

hTotalCosNewOBS->Scale(1/hTotalCosNewOBS->Integral());

hTotalCosNewRS->SetLineColor(kBlue);
hTotalCosNewRS->SetLineWidth(2);

hTotalCosNewBS->SetLineColor(kRed);
hTotalCosNewBS->SetLineWidth(2);

hTotalCosNewOBS->SetLineColor(kBlack);
hTotalCosNewOBS->SetLineWidth(2);

hTotalCosNewBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hTotalCosNewBS->GetXaxis()->CenterTitle();

hTotalCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hTotalCosNewBS->GetYaxis()->CenterTitle();

hTotalCosNewBS->Draw("histo");
hTotalCosNewRS->Draw("histosame");
hTotalCosNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg2 = new TLegend();
leg2 = new TLegend(0.58,0.65,0.88,0.88);
leg2->SetTextSize(0.04);
leg2->SetTextAlign(12);
leg2->SetFillColor(kWhite);
leg2->SetLineColor(kWhite);
leg2->SetShadowColor(kWhite);
leg2->SetHeader("SciBooNE MC");
leg2->AddEntry(hTotalCosNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg2->AddEntry(hTotalCosNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg2->AddEntry(hTotalCosNewOBS, "NEUT v5.0.1 Rein-Sehgal");
leg2->Draw();




// ########################################
// # Drawing the Good Momentum Histograms #
// ########################################

TCanvas *c4 = new TCanvas("c4", "Good Muon Momentums");
c4->SetTicks();
c4->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalGoodPNewRS->Scale(1/hTotalGoodPNewRS->Integral());

hTotalGoodPNewBS->Scale(1/hTotalGoodPNewBS->Integral());

hTotalGoodPNewOBS->Scale(1/hTotalGoodPNewOBS->Integral());

hTotalGoodPNewRS->SetLineColor(kBlue);
hTotalGoodPNewRS->SetLineWidth(2);

hTotalGoodPNewBS->SetLineColor(kRed);
hTotalGoodPNewBS->SetLineWidth(2);

hTotalGoodPNewOBS->SetLineColor(kBlack);
hTotalGoodPNewOBS->SetLineWidth(2);

hTotalGoodPNewBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hTotalGoodPNewBS->GetXaxis()->CenterTitle();

hTotalGoodPNewBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hTotalGoodPNewBS->GetYaxis()->CenterTitle();

hTotalGoodPNewBS->Draw("histo");
hTotalGoodPNewRS->Draw("histosame");
hTotalGoodPNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg3 = new TLegend();
leg3 = new TLegend(0.58,0.65,0.88,0.88);
leg3->SetTextSize(0.04);
leg3->SetTextAlign(12);
leg3->SetFillColor(kWhite);
leg3->SetLineColor(kWhite);
leg3->SetShadowColor(kWhite);
leg3->SetHeader("SciBooNE MC");
leg3->AddEntry(hTotalGoodPNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg3->AddEntry(hTotalGoodPNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg3->AddEntry(hTotalGoodPNewOBS, "NEUT v5.0.1 Rein-Sehgal");
leg3->Draw();




// ######################################
// # Drawing the Good Cosine Histograms #
// ######################################

TCanvas *c5 = new TCanvas("c5", "Good Muon Angles");
c5->SetTicks();
c5->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalGoodCosNewRS->Scale(1/hTotalGoodCosNewRS->Integral());

hTotalGoodCosNewBS->Scale(1/hTotalGoodCosNewBS->Integral());

hTotalGoodCosNewOBS->Scale(1/hTotalGoodCosNewOBS->Integral());

hTotalGoodCosNewRS->SetLineColor(kBlue);
hTotalGoodCosNewRS->SetLineWidth(2);

hTotalGoodCosNewBS->SetLineColor(kRed);
hTotalGoodCosNewBS->SetLineWidth(2);

hTotalGoodCosNewOBS->SetLineColor(kBlack);
hTotalGoodCosNewOBS->SetLineWidth(2);

hTotalGoodCosNewBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hTotalGoodCosNewBS->GetXaxis()->CenterTitle();

hTotalGoodCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hTotalGoodCosNewBS->GetYaxis()->CenterTitle();

hTotalGoodCosNewBS->Draw("histo");
hTotalGoodCosNewRS->Draw("histosame");
hTotalGoodCosNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg4 = new TLegend();
leg4 = new TLegend(0.58,0.65,0.88,0.88);
leg4->SetTextSize(0.04);
leg4->SetTextAlign(12);
leg4->SetFillColor(kWhite);
leg4->SetLineColor(kWhite);
leg4->SetShadowColor(kWhite);
leg4->SetHeader("SciBooNE MC");
leg4->AddEntry(hTotalGoodCosNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg4->AddEntry(hTotalGoodCosNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg4->AddEntry(hTotalGoodCosNewOBS, "NEUT v5.0.1 Rein-Sehgal");
leg4->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c10 = new TCanvas("c10", "Muon Momentums");
c10->SetTicks();
c10->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodStoppedPNewRS->Scale(1/hGoodStoppedPNewRS->Integral());

hGoodStoppedPNewBS->Scale(1/hGoodStoppedPNewBS->Integral());

hGoodStoppedPNewOBS->Scale(1/hGoodStoppedPNewOBS->Integral());

hGoodStoppedPNewRS->SetLineColor(kBlue);
hGoodStoppedPNewRS->SetLineWidth(2);

hGoodStoppedPNewBS->SetLineColor(kRed);
hGoodStoppedPNewBS->SetLineWidth(2);

hGoodStoppedPNewOBS->SetLineColor(kBlack);
hGoodStoppedPNewOBS->SetLineWidth(2);

hGoodStoppedPNewOBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hGoodStoppedPNewOBS->GetXaxis()->CenterTitle();

hGoodStoppedPNewOBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hGoodStoppedPNewOBS->GetYaxis()->CenterTitle();

hGoodStoppedPNewOBS->Draw("histo");
hGoodStoppedPNewBS->Draw("histosame");
hGoodStoppedPNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg9 = new TLegend();
leg9 = new TLegend(0.58,0.65,0.88,0.88);
leg9->SetTextSize(0.04);
leg9->SetTextAlign(12);
leg9->SetFillColor(kWhite);
leg9->SetLineColor(kWhite);
leg9->SetShadowColor(kWhite);
leg9->SetHeader("SciBooNE MC");
leg9->AddEntry(hGoodStoppedPNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg9->AddEntry(hGoodStoppedPNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg9->AddEntry(hGoodStoppedPNewOBS,"NEUT v5.0.1 Rein-Sehgal");
leg9->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c7 = new TCanvas("c7", "Muon Momentums");
c7->SetTicks();
c7->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodNonStoppedPNewRS->Scale(1/hGoodNonStoppedPNewRS->Integral());

hGoodNonStoppedPNewBS->Scale(1/hGoodNonStoppedPNewBS->Integral());

hGoodNonStoppedPNewOBS->Scale(1/hGoodNonStoppedPNewOBS->Integral());

hGoodNonStoppedPNewRS->SetLineColor(kBlue);
hGoodNonStoppedPNewRS->SetLineWidth(2);

hGoodNonStoppedPNewBS->SetLineColor(kRed);
hGoodNonStoppedPNewBS->SetLineWidth(2);

hGoodNonStoppedPNewOBS->SetLineColor(kBlack);
hGoodNonStoppedPNewOBS->SetLineWidth(2);

hGoodNonStoppedPNewOBS->GetXaxis()->SetTitle("Muon Momentum (MeV)");
hGoodNonStoppedPNewOBS->GetXaxis()->CenterTitle();

hGoodNonStoppedPNewOBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hGoodNonStoppedPNewOBS->GetYaxis()->CenterTitle();

hGoodNonStoppedPNewOBS->Draw("histo");
hGoodNonStoppedPNewRS->Draw("histosame");
hGoodNonStoppedPNewBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg6 = new TLegend();
leg6 = new TLegend(0.58,0.65,0.88,0.88);
leg6->SetTextSize(0.04);
leg6->SetTextAlign(12);
leg6->SetFillColor(kWhite);
leg6->SetLineColor(kWhite);
leg6->SetShadowColor(kWhite);
leg6->SetHeader("SciBooNE MC");
leg6->AddEntry(hGoodNonStoppedPNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg6->AddEntry(hGoodNonStoppedPNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg6->AddEntry(hGoodNonStoppedPNewOBS,"NEUT v5.0.1 Rein-Sehgal");
leg6->Draw();




// ################################
// # Drawing the Angle Histograms #
// ################################

TCanvas *c8 = new TCanvas("c8", "Muon Angles");
c8->SetTicks();
c8->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodNonStoppedCosNewRS->Scale(1/hGoodNonStoppedCosNewRS->Integral());

hGoodNonStoppedCosNewBS->Scale(1/hGoodNonStoppedCosNewBS->Integral());

hGoodNonStoppedCosNewOBS->Scale(1/hGoodNonStoppedCosNewOBS->Integral());

hGoodNonStoppedCosNewRS->SetLineColor(kBlue);
hGoodNonStoppedCosNewRS->SetLineWidth(2);

hGoodNonStoppedCosNewBS->SetLineColor(kRed);
hGoodNonStoppedCosNewBS->SetLineWidth(2);

hGoodNonStoppedCosNewOBS->SetLineColor(kBlack);
hGoodNonStoppedCosNewOBS->SetLineWidth(2);

hGoodNonStoppedCosNewOBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hGoodNonStoppedCosNewOBS->GetXaxis()->CenterTitle();

hGoodNonStoppedCosNewOBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hGoodNonStoppedCosNewOBS->GetYaxis()->CenterTitle();

hGoodNonStoppedCosNewOBS->Draw("histo");
hGoodNonStoppedCosNewRS->Draw("histosame");
hGoodNonStoppedCosNewBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg7 = new TLegend();
leg7 = new TLegend(0.58,0.65,0.88,0.88);
leg7->SetTextSize(0.04);
leg7->SetTextAlign(12);
leg7->SetFillColor(kWhite);
leg7->SetLineColor(kWhite);
leg7->SetShadowColor(kWhite);
leg7->SetHeader("SciBooNE MC");
leg7->AddEntry(hGoodNonStoppedCosNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg7->AddEntry(hGoodNonStoppedCosNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg7->AddEntry(hGoodNonStoppedCosNewOBS,"NEUT v5.0.1 Rein-Sehgal");
leg7->Draw();




// ####################################
// ### Drawing the Angle Histograms ###
// ####################################

TCanvas *c9 = new TCanvas("c9", "Muon Angles");
c9->SetTicks();
c9->SetFillColor(kWhite);

// Area normalzing the plot 
hGoodStoppedCosNewRS->Scale(1/hGoodStoppedCosNewRS->Integral());

hGoodStoppedCosNewBS->Scale(1/hGoodStoppedCosNewBS->Integral());

hGoodStoppedCosNewOBS->Scale(1/hGoodStoppedCosNewOBS->Integral());

hGoodStoppedCosNewRS->SetLineColor(kBlue);
hGoodStoppedCosNewRS->SetLineWidth(2);

hGoodStoppedCosNewBS->SetLineColor(kRed);
hGoodStoppedCosNewBS->SetLineWidth(2);

hGoodStoppedCosNewOBS->SetLineColor(kBlack);
hGoodStoppedCosNewOBS->SetLineWidth(2);

hGoodStoppedCosNewBS->GetXaxis()->SetTitle("Muon Theta (Degrees)");
hGoodStoppedCosNewBS->GetXaxis()->CenterTitle();

hGoodStoppedCosNewBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hGoodStoppedCosNewBS->GetYaxis()->CenterTitle();

hGoodStoppedCosNewBS->Draw("histo");
hGoodStoppedCosNewRS->Draw("histosame");
hGoodStoppedCosNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg8 = new TLegend();
leg8 = new TLegend(0.58,0.65,0.88,0.88);
leg8->SetTextSize(0.04);
leg8->SetTextAlign(12);
leg8->SetFillColor(kWhite);
leg8->SetLineColor(kWhite);
leg8->SetShadowColor(kWhite);
leg8->SetHeader("SciBooNE MC");
leg8->AddEntry(hGoodStoppedCosNewRS,"NEUT v5.3.6 Rein-Sehgal");
leg8->AddEntry(hGoodStoppedCosNewBS,"NEUT v5.3.6 Berger-Sehgal");
leg8->AddEntry(hGoodStoppedCosNewOBS,"NEUT v5.0.1 Rein-Sehgal");
leg8->Draw();




// ###########################################
// # Drawing the 2D RS Efficiency Histograms #
// ###########################################

TCanvas *c17 = new TCanvas("c17", "2D R-S Muon Efficiency Histogram");
c17->SetTicks();
c17->SetFillColor(kWhite);

Ratio2DRS->Draw("colz");




// ###########################################
// # Drawing the 2D BS Efficiency Histograms #
// ###########################################

TCanvas *c18 = new TCanvas("c18", "2D B-S Muon Efficiency Histogram");
c18->SetTicks();
c18->SetFillColor(kWhite);

Ratio2DBS->Draw("colz");




// ############################################
// # Drawing the 2D OBS Efficiency Histograms #
// ############################################

TCanvas *c19 = new TCanvas("c19", "2D Old R-S Muon Efficiency Histogram");
c19->SetTicks();
c19->SetFillColor(kWhite);

Ratio2DOBS->Draw("colz");




// ############################################
// # Drawing Berger-Sehgal Mom and Cos Ratios #
// ############################################

TCanvas *c20 = new TCanvas("c20", "Berger-Sehgal Momentum Ratios for Non-Stopped and Stopped");
c20->SetTicks();
c20->SetFillColor(kWhite);

RatioNSPBS->Draw("histo");
RatioSPBS->Draw("histosame");


TCanvas *c21 = new TCanvas("c21", "Berger-Sehgal Angle Ratios for Non-Stopped and Stopped");
c21->SetTicks();
c21->SetFillColor(kWhite);

RatioSCBS->Draw("histo");
RatioNSCBS->Draw("histosame");




// ##########################################
// # Drawing Rein-Sehgal Mom and Cos Ratios #
// ##########################################

TCanvas *c22 = new TCanvas("c22", "Rein-Sehgal Momentum Ratios for Non-Stopped and Stopped");
c22->SetTicks();
c22->SetFillColor(kWhite);

RatioNSPRS->Draw("histo");
RatioSPRS->Draw("histosame");


TCanvas *c23 = new TCanvas("c23", "Rein-Sehgal Angle Ratios for Non-Stopped and Stopped");
c23->SetTicks();
c23->SetFillColor(kWhite);

RatioSCRS->Draw("histo");
RatioNSCRS->Draw("histosame");




// ##############################################
// # Drawing Old Rein-Sehgal Mom and Cos Ratios #
// ##############################################

TCanvas *c24 = new TCanvas("c24", "Old Rein-Sehgal Momentum Ratios for Non-Stopped and Stopped");
c24->SetTicks();
c24->SetFillColor(kWhite);

RatioNSPOBS->Draw("histo");
RatioSPOBS->Draw("histosame");


TCanvas *c25 = new TCanvas("c25", "Old Rein-Sehgal Angle Ratios for Non-Stopped and Stopped");
c25->SetTicks();
c25->SetFillColor(kWhite);

RatioNSCOBS->Draw("histo");
RatioSCOBS->Draw("histosame");




// ###########################################
// # Drawing the 2D RS Efficiency Histograms #
// ###########################################

TCanvas *c26 = new TCanvas("c126", "2D R-S Muon Efficiency Histogram");
c26->SetTicks();
c26->SetFillColor(kWhite);

Ratio2DRSCC->Draw("colz");




// ###########################################
// # Drawing the 2D BS Efficiency Histograms #
// ###########################################

TCanvas *c27 = new TCanvas("c27", "2D B-S Muon Efficiency Histogram");
c27->SetTicks();
c27->SetFillColor(kWhite);

Ratio2DBSCC->Draw("colz");




// ############################################
// # Drawing the 2D OBS Efficiency Histograms #
// ############################################

TCanvas *c28 = new TCanvas("c28", "2D Old R-S Muon Efficiency Histogram");
c28->SetTicks();
c28->SetFillColor(kWhite);

Ratio2DOBSCC->Draw("colz");



/*
// #####################################################
// # Drawing the Good Pion Energy Efficiency Histogram #
// #####################################################

TCanvas *c26 = new TCanvas("c26", "Pion Good Energy Efficiencies Histogram");
c26->SetTicks();
c26->SetFillColor(kWhite);

PionEnergyRatioBS->Draw("E1");
PionEnergyRatioRS->Draw("E1same");
PionEnergyRatioOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg16 = new TLegend();
leg16 = new TLegend(0.58,0.65,0.88,0.88);
leg16->SetTextSize(0.04);
leg16->SetTextAlign(12);
leg16->SetFillColor(kWhite);
leg16->SetLineColor(kWhite);
leg16->SetShadowColor(kWhite);
leg16->SetHeader("SciBooNE MC");
leg16->AddEntry(PionEnergyRatioRS,"New R-S Model");
leg16->AddEntry(PionEnergyRatioBS,"New B-S Model");
leg16->AddEntry(PionEnergyRatioOBS,"Old B-S Model");
leg16->Draw();




// #######################################################
// # Drawing the Good Pion Momentum Efficiency Histogram #
// #######################################################

TCanvas *c27 = new TCanvas("c27", "Pion Good Momentum Efficiencies Histogram");
c27->SetTicks();
c27->SetFillColor(kWhite);

PionMomentumRatioBS->Draw("E1");
PionMomentumRatioRS->Draw("E1same");
PionMomentumRatioOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg17 = new TLegend();
leg17 = new TLegend(0.58,0.65,0.88,0.88);
leg17->SetTextSize(0.04);
leg17->SetTextAlign(12);
leg17->SetFillColor(kWhite);
leg17->SetLineColor(kWhite);
leg17->SetShadowColor(kWhite);
leg17->SetHeader("SciBooNE MC");
leg17->AddEntry(PionMomentumRatioRS,"New R-S Model");
leg17->AddEntry(PionMomentumRatioBS,"New B-S Model");
leg17->AddEntry(PionMomentumRatioOBS,"Old B-S Model");
leg17->Draw();




// #######################################################
// # Drawing the Good Pion Angles Efficiency Histogram #
// #######################################################

TCanvas *c28 = new TCanvas("c28", "Pion Good Angle Efficiencies Histogram");
c28->SetTicks();
c28->SetFillColor(kWhite);

PionAngleRatioBS->Draw("E1");
PionAngleRatioRS->Draw("E1same");
PionAngleRatioOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg18 = new TLegend();
leg18 = new TLegend(0.58,0.65,0.88,0.88);
leg18->SetTextSize(0.04);
leg18->SetTextAlign(12);
leg18->SetFillColor(kWhite);
leg18->SetLineColor(kWhite);
leg18->SetShadowColor(kWhite);
leg18->SetHeader("SciBooNE MC");
leg18->AddEntry(PionAngleRatioRS,"New R-S Model");
leg18->AddEntry(PionAngleRatioBS,"New B-S Model");
leg18->AddEntry(PionAngleRatioOBS,"Old B-S Model");
leg18->Draw();




// ########################################################
// # Drawing the Stopped Pion Energy Efficiency Histogram #
// ########################################################

TCanvas *c29 = new TCanvas("c29", "Pion Stopped Energy Efficiencies Histogram");
c29->SetTicks();
c29->SetFillColor(kWhite);

PionEnergyRatioSBS->Draw("E1");
PionEnergyRatioSRS->Draw("E1same");
PionEnergyRatioSOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg19 = new TLegend();
leg19 = new TLegend(0.58,0.65,0.88,0.88);
leg19->SetTextSize(0.04);
leg19->SetTextAlign(12);
leg19->SetFillColor(kWhite);
leg19->SetLineColor(kWhite);
leg19->SetShadowColor(kWhite);
leg19->SetHeader("SciBooNE MC");
leg19->AddEntry(PionEnergyRatioSRS,"New R-S Model");
leg19->AddEntry(PionEnergyRatioSBS,"New B-S Model");
leg19->AddEntry(PionEnergyRatioSOBS,"Old B-S Model");
leg19->Draw();




// ##########################################################
// # Drawing the Stopped Pion Momentum Efficiency Histogram #
// ##########################################################

TCanvas *c30 = new TCanvas("c30", "Pion Stopped Momentum Efficiencies Histogram");
c30->SetTicks();
c30->SetFillColor(kWhite);

PionMomentumRatioSBS->Draw("E1");
PionMomentumRatioSRS->Draw("E1same");
PionMomentumRatioSOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg20 = new TLegend();
leg20 = new TLegend(0.58,0.65,0.88,0.88);
leg20->SetTextSize(0.04);
leg20->SetTextAlign(12);
leg20->SetFillColor(kWhite);
leg20->SetLineColor(kWhite);
leg20->SetShadowColor(kWhite);
leg20->SetHeader("SciBooNE MC");
leg20->AddEntry(PionMomentumRatioSRS,"New R-S Model");
leg20->AddEntry(PionMomentumRatioSBS,"New B-S Model");
leg20->AddEntry(PionMomentumRatioSOBS,"Old B-S Model");
leg20->Draw();




// ########################################################
// # Drawing the Stopped Pion Angles Efficiency Histogram #
// ########################################################

TCanvas *c31 = new TCanvas("c31", "Pion Stopped Angle Efficiencies Histogram");
c31->SetTicks();
c31->SetFillColor(kWhite);

PionAngleRatioSBS->Draw("E1");
PionAngleRatioSRS->Draw("E1same");
PionAngleRatioSOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg21 = new TLegend();
leg21 = new TLegend(0.58,0.65,0.88,0.88);
leg21->SetTextSize(0.04);
leg21->SetTextAlign(12);
leg21->SetFillColor(kWhite);
leg21->SetLineColor(kWhite);
leg21->SetShadowColor(kWhite);
leg21->SetHeader("SciBooNE MC");
leg21->AddEntry(PionAngleRatioSRS,"New R-S Model");
leg21->AddEntry(PionAngleRatioSBS,"New B-S Model");
leg21->AddEntry(PionAngleRatioSOBS,"Old B-S Model");
leg21->Draw();




// ############################################################
// # Drawing the Non-Stopped Pion Energy Efficiency Histogram #
// ############################################################

TCanvas *c32 = new TCanvas("c32", "Pion Non-Stopped Energy Efficiencies Histogram");
c32->SetTicks();
c32->SetFillColor(kWhite);

PionEnergyRatioNSBS->Draw("E1");
PionEnergyRatioNSRS->Draw("E1same");
PionEnergyRatioNSOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg22 = new TLegend();
leg22 = new TLegend(0.58,0.65,0.88,0.88);
leg22->SetTextSize(0.04);
leg22->SetTextAlign(12);
leg22->SetFillColor(kWhite);
leg22->SetLineColor(kWhite);
leg22->SetShadowColor(kWhite);
leg22->SetHeader("SciBooNE MC");
leg22->AddEntry(PionEnergyRatioNSRS,"New R-S Model");
leg22->AddEntry(PionEnergyRatioNSBS,"New B-S Model");
leg22->AddEntry(PionEnergyRatioNSOBS,"Old B-S Model");
leg22->Draw();




// ##############################################################
// # Drawing the Non-Stopped Pion Momentum Efficiency Histogram #
// ##############################################################

TCanvas *c33 = new TCanvas("c33", "Pion Non-Stopped Momentum Efficiencies Histogram");
c33->SetTicks();
c33->SetFillColor(kWhite);

PionMomentumRatioNSBS->Draw("E1");
PionMomentumRatioNSRS->Draw("E1same");
PionMomentumRatioNSOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg23 = new TLegend();
leg23 = new TLegend(0.58,0.65,0.88,0.88);
leg23->SetTextSize(0.04);
leg23->SetTextAlign(12);
leg23->SetFillColor(kWhite);
leg23->SetLineColor(kWhite);
leg23->SetShadowColor(kWhite);
leg23->SetHeader("SciBooNE MC");
leg23->AddEntry(PionMomentumRatioNSRS,"New R-S Model");
leg23->AddEntry(PionMomentumRatioNSBS,"New B-S Model");
leg23->AddEntry(PionMomentumRatioNSOBS,"Old B-S Model");
leg23->Draw();




// ############################################################
// # Drawing the Non-Stopped Pion Angles Efficiency Histogram #
// ############################################################

TCanvas *c34 = new TCanvas("c34", "Pion Non-Stopped Angle Efficiencies Histogram");
c34->SetTicks();
c34->SetFillColor(kWhite);

PionAngleRatioNSBS->Draw("E1");
PionAngleRatioNSRS->Draw("E1same");
PionAngleRatioNSOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg24 = new TLegend();
leg24 = new TLegend(0.58,0.65,0.88,0.88);
leg24->SetTextSize(0.04);
leg24->SetTextAlign(12);
leg24->SetFillColor(kWhite);
leg24->SetLineColor(kWhite);
leg24->SetShadowColor(kWhite);
leg24->SetHeader("SciBooNE MC");
leg24->AddEntry(PionAngleRatioNSRS,"New R-S Model");
leg24->AddEntry(PionAngleRatioNSBS,"New B-S Model");
leg24->AddEntry(PionAngleRatioNSOBS,"Old B-S Model");
leg24->Draw();
*/




// =================================================================================================================
//                              Accessing the bin information from the histograms
// =================================================================================================================

std::cout<<"|--------------------|"<<std::endl;
std::cout<<"  New Rein-Sehgal  "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
for (int i=1; i<21; i++) {
   for (int j=1; j<37; j++) {
      Int_t bin = Ratio2DRS->GetBin(j,i,1);
      Double_t binContent = Ratio2DRS->GetBinContent(bin);
      //std::cout<<j<<", "<<i<<", "<<bin<<", "<<binContent<<std::endl;
      //std::cout<<j<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<bin<<std::endl;
      std::cout<<binContent<<std::endl;
      }


   }
std::cout<<"|--------------------|"<<std::endl;


std::cout<<" "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
std::cout<<"  New Berger-Sehgal  "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
for (int i=1; i<21; i++) {
   for (int j=1; j<37; j++) {
      Int_t bin = Ratio2DBS->GetBin(j,i,1);
      Double_t binContent = Ratio2DBS->GetBinContent(bin);
      //std::cout<<j<<", "<<i<<", "<<bin<<", "<<binContent<<std::endl;
      //std::cout<<j<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<bin<<std::endl;
      std::cout<<binContent<<std::endl;
      }


   }
std::cout<<"|--------------------|"<<std::endl;


std::cout<<" "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
std::cout<<"  Old Rein-Sehgal  "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
for (int i=1; i<21; i++) {
   for (int j=1; j<37; j++) {
      Int_t bin = Ratio2DOBS->GetBin(j,i,1);
      Double_t binContent = Ratio2DOBS->GetBinContent(bin);
      //std::cout<<j<<", "<<i<<", "<<bin<<", "<<binContent<<std::endl;
      //std::cout<<j<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<bin<<std::endl;
      std::cout<<binContent<<std::endl;
      }


   }
std::cout<<"|--------------------|"<<std::endl;


std::cout<<" "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
std::cout<<"  New Rein-Sehgal CC "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
for (int i=1; i<21; i++) {
   for (int j=1; j<37; j++) {
      Int_t bin = Ratio2DRSCC->GetBin(j,i,1);
      Double_t binContent = Ratio2DRSCC->GetBinContent(bin);
      //std::cout<<j<<", "<<i<<", "<<bin<<", "<<binContent<<std::endl;
      //std::cout<<j<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<bin<<std::endl;
      std::cout<<binContent<<std::endl;
      }


   }
std::cout<<"|--------------------|"<<std::endl;


std::cout<<" "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
std::cout<<"  New Berger-Sehgal CC "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
for (int i=1; i<21; i++) {
   for (int j=1; j<37; j++) {
      Int_t bin = Ratio2DBSCC->GetBin(j,i,1);
      Double_t binContent = Ratio2DBSCC->GetBinContent(bin);
      //std::cout<<j<<", "<<i<<", "<<bin<<", "<<binContent<<std::endl;
      //std::cout<<j<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<bin<<std::endl;
      std::cout<<binContent<<std::endl;
      }


   }
std::cout<<"|--------------------|"<<std::endl;


std::cout<<" "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
std::cout<<"  Old Rein-Sehgal CC "<<std::endl;
std::cout<<"|--------------------|"<<std::endl;
for (int i=1; i<21; i++) {
   for (int j=1; j<37; j++) {
      Int_t bin = Ratio2DOBSCC->GetBin(j,i,1);
      Double_t binContent = Ratio2DOBSCC->GetBinContent(bin);
      //std::cout<<j<<", "<<i<<", "<<bin<<", "<<binContent<<std::endl;
      //std::cout<<j<<std::endl;
      //std::cout<<i<<std::endl;
      //std::cout<<bin<<std::endl;
      std::cout<<binContent<<std::endl;
      }


   }
std::cout<<"|--------------------|"<<std::endl;

// ================================================================================================================

TFile *TAcceptanceInfo = new TFile("./ROOTFILES/2DAcceptanceHistogramsNeuMode.root", "RECREATE");

Ratio2DRS->Write();
Ratio2DBS->Write();
Ratio2DOBS->Write();

Ratio2DRSCC->Write();
Ratio2DBSCC->Write();
Ratio2DOBSCC->Write();

}
