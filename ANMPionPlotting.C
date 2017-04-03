{
// ####################
// # Read in the Data #
// ####################


// =======================================================================================
//                     ### Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================

TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBS.root"); //Load Total Muon Info File

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

// ### Defining the ratio histogram ###
TH1D *PionEnergyRatioBS = new TH1D("PionEnergyRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioBS = new TH1D("PionMomentumRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioBS = new TH1D("PionAngleRatioBS", "Pion Efficiencies for Stopped and Non-Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioSBS = new TH1D("PionEnergyRatioSBS", "Pion Efficiencies for Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioSBS = new TH1D("PionMomentumRatioSBS", "Pion Efficiencies for Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioSBS = new TH1D("PionAngleRatioSBS", "Pion Efficiencies for Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioNSBS = new TH1D("PionEnergyRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioNSBS = new TH1D("PionMomentumRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioNSBS = new TH1D("PionAngleRatioNSBS", "Pion Efficiencies for Non-Stopped Muon Angle", 40, 0, 180);

// ### Formatting the plot ###
PionEnergyRatioBS->SetLineColor(kRed);
PionEnergyRatioBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioBS->GetXaxis()->CenterTitle();
PionEnergyRatioBS->GetYaxis()->SetTitle("Normalized Events");
PionEnergyRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioBS->SetLineColor(kRed);
PionMomentumRatioBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioBS->GetXaxis()->CenterTitle();
PionMomentumRatioBS->GetYaxis()->SetTitle("Normalized Events");
PionMomentumRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioBS->SetLineColor(kRed);
PionAngleRatioBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioBS->GetXaxis()->CenterTitle();
PionAngleRatioBS->GetYaxis()->SetTitle("Normalized Events");
PionAngleRatioBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioSBS->SetLineColor(kRed);
PionEnergyRatioSBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioSBS->GetXaxis()->CenterTitle();
PionEnergyRatioSBS->GetYaxis()->SetTitle("Normalized Events");
PionEnergyRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioSBS->SetLineColor(kRed);
PionMomentumRatioSBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioSBS->GetXaxis()->CenterTitle();
PionMomentumRatioSBS->GetYaxis()->SetTitle("Normalized Events");
PionMomentumRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioSBS->SetLineColor(kRed);
PionAngleRatioSBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioSBS->GetXaxis()->CenterTitle();
PionAngleRatioSBS->GetYaxis()->SetTitle("Normalized Events");
PionAngleRatioSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioNSBS->SetLineColor(kRed);
PionEnergyRatioNSBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioNSBS->GetXaxis()->CenterTitle();
PionEnergyRatioNSBS->GetYaxis()->SetTitle("Normalized Events");
PionEnergyRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioNSBS->SetLineColor(kRed);
PionMomentumRatioNSBS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioNSBS->GetXaxis()->CenterTitle();
PionMomentumRatioNSBS->GetYaxis()->SetTitle("Normalized Events");
PionMomentumRatioNSBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioNSBS->SetLineColor(kRed);
PionAngleRatioNSBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioNSBS->GetXaxis()->CenterTitle();
PionAngleRatioNSBS->GetYaxis()->SetTitle("Normalized Events");
PionAngleRatioNSBS->GetYaxis()->CenterTitle();


PionEnergyRatioBS->Divide(hPionEnergyGoodBS, hPionEnergyBS);
PionMomentumRatioBS->Divide(hPionMomentumGoodBS, hPionMomentumBS);
PionAngleRatioBS->Divide(hPionAngleGoodBS, hPionAngleBS);
PionEnergyRatioSBS->Divide(hPionEnergyStoppedBS, hPionEnergyGoodBS);
PionMomentumRatioSBS->Divide(hPionMomentumStoppedBS, hPionMomentumGoodBS);
PionAngleRatioSBS->Divide(hPionAngleStoppedBS, hPionAngleGoodBS);
PionEnergyRatioNSBS->Divide(hPionEnergyNonStoppedBS, hPionEnergyGoodBS);
PionMomentumRatioNSBS->Divide(hPionMomentumNonStoppedBS, hPionMomentumGoodBS);
PionAngleRatioNSBS->Divide(hPionAngleNonStoppedBS, hPionAngleGoodBS);




// =======================================================================================
//                    ### Rein Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f2 = new TFile("./ROOTFILES/totalmuoninfoRS.root"); //Load Total Muon Info File

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
TH1D *PionEnergyRatioRS = new TH1D("PionEnergyRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioRS = new TH1D("PionMomentumRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioRS = new TH1D("PionAngleRatioRS", "Pion Efficiencies for Stopped and Non-Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioSRS = new TH1D("PionEnergyRatioSRS", "Pion Efficiencies for Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioSRS = new TH1D("PionMomentumRatioSRS", "Pion Efficiencies for Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioSRS = new TH1D("PionAngleRatioSRS", "Pion Efficiencies for Stopped Muon Angle", 40, 0, 180);
TH1D *PionEnergyRatioNSRS = new TH1D("PionEnergyRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Energy", 40, 0, 2500);
TH1D *PionMomentumRatioNSRS = new TH1D("PionMomentumRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Momentum", 40, 0, 2500);
TH1D *PionAngleRatioNSRS = new TH1D("PionAngleRatioNSRS", "Pion Efficiencies for Non-Stopped Muon Angle", 40, 0, 180);

// ### Formatting the plot ###
PionEnergyRatioRS->SetLineColor(kBlue);
PionEnergyRatioRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioRS->GetXaxis()->CenterTitle();
PionEnergyRatioRS->GetYaxis()->SetTitle("Normalized Events");
PionEnergyRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioRS->SetLineColor(kBlue);
PionMomentumRatioRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioRS->GetXaxis()->CenterTitle();
PionMomentumRatioRS->GetYaxis()->SetTitle("Normalized Events");
PionMomentumRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioRS->SetLineColor(kBlue);
PionAngleRatioRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioRS->GetXaxis()->CenterTitle();
PionAngleRatioRS->GetYaxis()->SetTitle("Normalized Events");
PionAngleRatioRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioSRS->SetLineColor(kBlue);
PionEnergyRatioSRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioSRS->GetXaxis()->CenterTitle();
PionEnergyRatioSRS->GetYaxis()->SetTitle("Normalized Events");
PionEnergyRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioSRS->SetLineColor(kBlue);
PionMomentumRatioSRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioSRS->GetXaxis()->CenterTitle();
PionMomentumRatioSRS->GetYaxis()->SetTitle("Normalized Events");
PionMomentumRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioSRS->SetLineColor(kBlue);
PionAngleRatioSRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioSRS->GetXaxis()->CenterTitle();
PionAngleRatioSRS->GetYaxis()->SetTitle("Normalized Events");
PionAngleRatioSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionEnergyRatioNSRS->SetLineColor(kBlue);
PionEnergyRatioNSRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
PionEnergyRatioNSRS->GetXaxis()->CenterTitle();
PionEnergyRatioNSRS->GetYaxis()->SetTitle("Normalized Events");
PionEnergyRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionMomentumRatioNSRS->SetLineColor(kBlue);
PionMomentumRatioNSRS->GetXaxis()->SetTitle("Pion Momentum Magnitude (MeV)");
PionMomentumRatioNSRS->GetXaxis()->CenterTitle();
PionMomentumRatioNSRS->GetYaxis()->SetTitle("Normalized Events");
PionMomentumRatioNSRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
PionAngleRatioNSRS->SetLineColor(kBlue);
PionAngleRatioNSRS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
PionAngleRatioNSRS->GetXaxis()->CenterTitle();
PionAngleRatioNSRS->GetYaxis()->SetTitle("Normalized Events");
PionAngleRatioNSRS->GetYaxis()->CenterTitle();


PionEnergyRatioRS->Divide(hPionEnergyGoodRS, hPionEnergyRS);
PionMomentumRatioRS->Divide(hPionMomentumGoodRS, hPionMomentumRS);
PionAngleRatioRS->Divide(hPionAngleGoodRS, hPionAngleRS);
PionEnergyRatioSRS->Divide(hPionEnergyStoppedRS, hPionEnergyGoodRS);
PionMomentumRatioSRS->Divide(hPionMomentumStoppedRS, hPionMomentumGoodRS);
PionAngleRatioSRS->Divide(hPionAngleStoppedRS, hPionAngleGoodRS);
PionEnergyRatioNSRS->Divide(hPionEnergyNonStoppedRS, hPionEnergyGoodRS);
PionMomentumRatioNSRS->Divide(hPionMomentumNonStoppedRS, hPionMomentumGoodRS);
PionAngleRatioNSRS->Divide(hPionAngleNonStoppedRS, hPionAngleGoodRS);




// #################################################
// # Drawing the Total Pion Information Histograms #
// #################################################


// =================================================
//             ### Total Pion Energy ###
// =================================================
TCanvas *c1 = new TCanvas("c1", "Total Pion Energies");
c1->SetTicks();
c1->SetFillColor(kWhite);

// Area normalzing the plot 
hPionEnergyBS->Scale(1/hPionEnergyBS->Integral());
hPionEnergyRS->Scale(1/hPionEnergyRS->Integral());

hPionEnergyRS->SetLineColor(kBlue);
hPionEnergyRS->SetLineWidth(2);

hPionEnergyBS->SetLineColor(kRed);
hPionEnergyBS->SetLineWidth(2);

hPionEnergyBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
hPionEnergyBS->GetXaxis()->CenterTitle();

hPionEnergyBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionEnergyBS->GetYaxis()->CenterTitle();

hPionEnergyBS->Draw("histo");
hPionEnergyRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg1 = new TLegend();
leg1 = new TLegend(0.58,0.65,0.88,0.88);
leg1->SetTextSize(0.04);
leg1->SetTextAlign(12);
leg1->SetFillColor(kWhite);
leg1->SetLineColor(kWhite);
leg1->SetShadowColor(kWhite);
leg1->SetHeader("SciBooNE MC");
leg1->AddEntry(hPionEnergyRS,"New R-S Model");
leg1->AddEntry(hPionEnergyBS,"New B-S Model");
leg1->Draw();
// =================================================


// =================================================
//             ### Total Pion Momentum ###
// =================================================
TCanvas *c2 = new TCanvas("c2", "Total Pion Momentums");
c2->SetTicks();
c2->SetFillColor(kWhite);

// Area normalzing the plot 
hPionMomentumBS->Scale(1/hPionMomentumBS->Integral());
hPionMomentumRS->Scale(1/hPionMomentumRS->Integral());

hPionMomentumRS->SetLineColor(kBlue);
hPionMomentumRS->SetLineWidth(2);

hPionMomentumBS->SetLineColor(kRed);
hPionMomentumBS->SetLineWidth(2);

hPionMomentumBS->GetXaxis()->SetTitle("Pion Momentum (MeV)");
hPionMomentumBS->GetXaxis()->CenterTitle();

hPionMomentumBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionMomentumBS->GetYaxis()->CenterTitle();

hPionMomentumBS->Draw("histo");
hPionMomentumRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg2 = new TLegend();
leg2 = new TLegend(0.58,0.65,0.88,0.88);
leg2->SetTextSize(0.04);
leg2->SetTextAlign(12);
leg2->SetFillColor(kWhite);
leg2->SetLineColor(kWhite);
leg2->SetShadowColor(kWhite);
leg2->SetHeader("SciBooNE MC");
leg2->AddEntry(hPionMomentumRS,"New R-S Model");
leg2->AddEntry(hPionMomentumBS,"New B-S Model");
leg2->Draw();
// =================================================


// =================================================
//             ### Total Pion Angle ###
// =================================================
TCanvas *c3 = new TCanvas("c3", "Total Pion Angles");
c3->SetTicks();
c3->SetFillColor(kWhite);

// Area normalzing the plot 
hPionAngleBS->Scale(1/hPionAngleBS->Integral());
hPionAngleRS->Scale(1/hPionAngleRS->Integral());

hPionAngleRS->SetLineColor(kBlue);
hPionAngleRS->SetLineWidth(2);

hPionAngleBS->SetLineColor(kRed);
hPionAngleBS->SetLineWidth(2);

hPionAngleBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
hPionAngleBS->GetXaxis()->CenterTitle();

hPionAngleBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hPionAngleBS->GetYaxis()->CenterTitle();

hPionAngleBS->Draw("histo");
hPionAngleRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg3 = new TLegend();
leg3 = new TLegend(0.58,0.65,0.88,0.88);
leg3->SetTextSize(0.04);
leg3->SetTextAlign(12);
leg3->SetFillColor(kWhite);
leg3->SetLineColor(kWhite);
leg3->SetShadowColor(kWhite);
leg3->SetHeader("SciBooNE MC");
leg3->AddEntry(hPionAngleRS,"New R-S Model");
leg3->AddEntry(hPionAngleBS,"New B-S Model");
leg3->Draw();
// =================================================

// #################################################




// ################################################
// # Drawing the Good Pion Information Histograms #
// ################################################


// ================================================
//              ### Good Pion Energy ###
// ================================================
TCanvas *c4 = new TCanvas("c4", "Good Pion Energies");
c4->SetTicks();
c4->SetFillColor(kWhite);

// Area normalzing the plot 
hPionEnergyGoodBS->Scale(1/hPionEnergyGoodBS->Integral());
hPionEnergyGoodRS->Scale(1/hPionEnergyGoodRS->Integral());

hPionEnergyGoodRS->SetLineColor(kBlue);
hPionEnergyGoodRS->SetLineWidth(2);

hPionEnergyGoodBS->SetLineColor(kRed);
hPionEnergyGoodBS->SetLineWidth(2);

hPionEnergyGoodRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
hPionEnergyGoodRS->GetXaxis()->CenterTitle();

hPionEnergyGoodRS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionEnergyGoodRS->GetYaxis()->CenterTitle();

hPionEnergyGoodRS->Draw("histo");
hPionEnergyGoodBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg4 = new TLegend();
leg4 = new TLegend(0.58,0.65,0.88,0.88);
leg4->SetTextSize(0.04);
leg4->SetTextAlign(12);
leg4->SetFillColor(kWhite);
leg4->SetLineColor(kWhite);
leg4->SetShadowColor(kWhite);
leg4->SetHeader("SciBooNE MC");
leg4->AddEntry(hPionEnergyGoodRS,"New R-S Model");
leg4->AddEntry(hPionEnergyGoodBS,"New B-S Model");
leg4->Draw();
// ================================================


// ================================================
//             ### Good Pion Momentum ###
// ================================================
TCanvas *c5 = new TCanvas("c5", "Good Pion Momentums");
c5->SetTicks();
c5->SetFillColor(kWhite);

// Area normalzing the plot 
hPionMomentumGoodBS->Scale(1/hPionMomentumGoodBS->Integral());
hPionMomentumGoodRS->Scale(1/hPionMomentumGoodRS->Integral());

hPionMomentumGoodRS->SetLineColor(kBlue);
hPionMomentumGoodRS->SetLineWidth(2);

hPionMomentumGoodBS->SetLineColor(kRed);
hPionMomentumGoodBS->SetLineWidth(2);

hPionMomentumGoodRS->GetXaxis()->SetTitle("Pion Momentum (MeV)");
hPionMomentumGoodRS->GetXaxis()->CenterTitle();

hPionMomentumGoodRS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionMomentumGoodRS->GetYaxis()->CenterTitle();

hPionMomentumGoodRS->Draw("histo");
hPionMomentumGoodBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg5 = new TLegend();
leg5 = new TLegend(0.58,0.65,0.88,0.88);
leg5->SetTextSize(0.04);
leg5->SetTextAlign(12);
leg5->SetFillColor(kWhite);
leg5->SetLineColor(kWhite);
leg5->SetShadowColor(kWhite);
leg5->SetHeader("SciBooNE MC");
leg5->AddEntry(hPionMomentumGoodRS,"New R-S Model");
leg5->AddEntry(hPionMomentumGoodBS,"New B-S Model");
leg5->Draw();
// ================================================


// ================================================
//              ### Good Pion Angle ###
// ================================================
TCanvas *c6 = new TCanvas("c6", "Good Pion Angles");
c6->SetTicks();
c6->SetFillColor(kWhite);

// Area normalzing the plot 
hPionAngleGoodBS->Scale(1/hPionAngleGoodBS->Integral());
hPionAngleGoodRS->Scale(1/hPionAngleGoodRS->Integral());

hPionAngleGoodRS->SetLineColor(kBlue);
hPionAngleGoodRS->SetLineWidth(2);

hPionAngleGoodBS->SetLineColor(kRed);
hPionAngleGoodBS->SetLineWidth(2);

hPionAngleGoodBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
hPionAngleGoodBS->GetXaxis()->CenterTitle();

hPionAngleGoodBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hPionAngleGoodBS->GetYaxis()->CenterTitle();

hPionAngleGoodBS->Draw("histo");
hPionAngleGoodRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg6 = new TLegend();
leg6 = new TLegend(0.58,0.65,0.88,0.88);
leg6->SetTextSize(0.04);
leg6->SetTextAlign(12);
leg6->SetFillColor(kWhite);
leg6->SetLineColor(kWhite);
leg6->SetShadowColor(kWhite);
leg6->SetHeader("SciBooNE MC");
leg6->AddEntry(hPionAngleGoodRS,"New R-S Model");
leg6->AddEntry(hPionAngleGoodBS,"New B-S Model");
leg6->Draw();
// ================================================

// ################################################




// ###################################################
// # Drawing the Stopped Pion Information Histograms #
// ###################################################


// ===================================================
//             ### Stopped Pion Energy ###
// ===================================================
TCanvas *c7 = new TCanvas("c7", "Stopped Pion Energies");
c7->SetTicks();
c7->SetFillColor(kWhite);

// Area normalzing the plot 
hPionEnergyStoppedBS->Scale(1/hPionEnergyStoppedBS->Integral());
hPionEnergyStoppedRS->Scale(1/hPionEnergyStoppedRS->Integral());

hPionEnergyStoppedRS->SetLineColor(kBlue);
hPionEnergyStoppedRS->SetLineWidth(2);

hPionEnergyStoppedBS->SetLineColor(kRed);
hPionEnergyStoppedBS->SetLineWidth(2);

hPionEnergyStoppedBS->GetXaxis()->SetTitle("Pion Energy (MeV)");
hPionEnergyStoppedBS->GetXaxis()->CenterTitle();

hPionEnergyStoppedBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionEnergyStoppedBS->GetYaxis()->CenterTitle();

hPionEnergyStoppedBS->Draw("histo");
hPionEnergyStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg7 = new TLegend();
leg7 = new TLegend(0.58,0.65,0.88,0.88);
leg7->SetTextSize(0.04);
leg7->SetTextAlign(12);
leg7->SetFillColor(kWhite);
leg7->SetLineColor(kWhite);
leg7->SetShadowColor(kWhite);
leg7->SetHeader("SciBooNE MC");
leg7->AddEntry(hPionEnergyStoppedRS,"New R-S Model");
leg7->AddEntry(hPionEnergyStoppedBS,"New B-S Model");
leg7->Draw();
// ===================================================


// ===================================================
//            ### Stopped Pion Momentum ###
// ===================================================
TCanvas *c8 = new TCanvas("c8", "Stopped Pion Momentums");
c8->SetTicks();
c8->SetFillColor(kWhite);

// Area normalzing the plot 
hPionMomentumStoppedBS->Scale(1/hPionMomentumStoppedBS->Integral());
hPionMomentumStoppedRS->Scale(1/hPionMomentumStoppedRS->Integral());

hPionMomentumStoppedRS->SetLineColor(kBlue);
hPionMomentumStoppedRS->SetLineWidth(2);

hPionMomentumStoppedBS->SetLineColor(kRed);
hPionMomentumStoppedBS->SetLineWidth(2);

hPionMomentumStoppedBS->GetXaxis()->SetTitle("Pion Momentum (MeV)");
hPionMomentumStoppedBS->GetXaxis()->CenterTitle();

hPionMomentumStoppedBS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionMomentumStoppedBS->GetYaxis()->CenterTitle();

hPionMomentumStoppedBS->Draw("histo");
hPionMomentumStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg8 = new TLegend();
leg8 = new TLegend(0.58,0.65,0.88,0.88);
leg8->SetTextSize(0.04);
leg8->SetTextAlign(12);
leg8->SetFillColor(kWhite);
leg8->SetLineColor(kWhite);
leg8->SetShadowColor(kWhite);
leg8->SetHeader("SciBooNE MC");
leg8->AddEntry(hPionMomentumStoppedRS,"New R-S Model");
leg8->AddEntry(hPionMomentumStoppedBS,"New B-S Model");
leg8->Draw();
// ===================================================


// ===================================================
//             ### Stopped Pion Angle ###
// ===================================================
TCanvas *c9 = new TCanvas("c9", "Stopped Pion Angles");
c9->SetTicks();
c9->SetFillColor(kWhite);

// Area normalzing the plot 
hPionAngleStoppedBS->Scale(1/hPionAngleStoppedBS->Integral());
hPionAngleStoppedRS->Scale(1/hPionAngleStoppedRS->Integral());

hPionAngleStoppedRS->SetLineColor(kBlue);
hPionAngleStoppedRS->SetLineWidth(2);

hPionAngleStoppedBS->SetLineColor(kRed);
hPionAngleStoppedBS->SetLineWidth(2);

hPionAngleStoppedBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
hPionAngleStoppedBS->GetXaxis()->CenterTitle();

hPionAngleStoppedBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hPionAngleStoppedBS->GetYaxis()->CenterTitle();

hPionAngleStoppedBS->Draw("histo");
hPionAngleStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg9 = new TLegend();
leg9 = new TLegend(0.58,0.65,0.88,0.88);
leg9->SetTextSize(0.04);
leg9->SetTextAlign(12);
leg9->SetFillColor(kWhite);
leg9->SetLineColor(kWhite);
leg9->SetShadowColor(kWhite);
leg9->SetHeader("SciBooNE MC");
leg9->AddEntry(hPionAngleStoppedRS,"New R-S Model");
leg9->AddEntry(hPionAngleStoppedBS,"New B-S Model");
leg9->Draw();
// ===================================================

// ###################################################




// #######################################################
// # Drawing the Non-Stopped Pion Information Histograms #
// #######################################################


// =======================================================
//             ### Non-Stopped Pion Energy ###
// =======================================================
TCanvas *c10 = new TCanvas("c10", "Non-Stopped Pion Energies");
c10->SetTicks();
c10->SetFillColor(kWhite);

// Area normalzing the plot 
hPionEnergyNonStoppedBS->Scale(1/hPionEnergyNonStoppedBS->Integral());
hPionEnergyNonStoppedRS->Scale(1/hPionEnergyNonStoppedRS->Integral());

hPionEnergyNonStoppedRS->SetLineColor(kBlue);
hPionEnergyNonStoppedRS->SetLineWidth(2);

hPionEnergyNonStoppedBS->SetLineColor(kRed);
hPionEnergyNonStoppedBS->SetLineWidth(2);

hPionEnergyNonStoppedRS->GetXaxis()->SetTitle("Pion Energy (MeV)");
hPionEnergyNonStoppedRS->GetXaxis()->CenterTitle();

hPionEnergyNonStoppedRS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionEnergyNonStoppedRS->GetYaxis()->CenterTitle();

hPionEnergyNonStoppedRS->Draw("histo");
hPionEnergyNonStoppedBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg10 = new TLegend();
leg10 = new TLegend(0.58,0.65,0.88,0.88);
leg10->SetTextSize(0.04);
leg10->SetTextAlign(12);
leg10->SetFillColor(kWhite);
leg10->SetLineColor(kWhite);
leg10->SetShadowColor(kWhite);
leg10->SetHeader("SciBooNE MC");
leg10->AddEntry(hPionEnergyNonStoppedRS,"New R-S Model");
leg10->AddEntry(hPionEnergyNonStoppedBS,"New B-S Model");
leg10->Draw();
// =======================================================


// =======================================================
//            ### Non-Stopped Pion Momentum ###
// =======================================================
TCanvas *c11 = new TCanvas("c11", "Non-Stopped Pion Momentums");
c11->SetTicks();
c11->SetFillColor(kWhite);

// Area normalzing the plot 
hPionMomentumNonStoppedBS->Scale(1/hPionMomentumNonStoppedBS->Integral());
hPionMomentumNonStoppedRS->Scale(1/hPionMomentumNonStoppedRS->Integral());

hPionMomentumNonStoppedRS->SetLineColor(kBlue);
hPionMomentumNonStoppedRS->SetLineWidth(2);

hPionMomentumNonStoppedBS->SetLineColor(kRed);
hPionMomentumNonStoppedBS->SetLineWidth(2);

hPionMomentumNonStoppedRS->GetXaxis()->SetTitle("Pion Momentum (MeV)");
hPionMomentumNonStoppedRS->GetXaxis()->CenterTitle();

hPionMomentumNonStoppedRS->GetYaxis()->SetTitle("Normalized Events (/ 50MeV)");
hPionMomentumNonStoppedRS->GetYaxis()->CenterTitle();

hPionMomentumNonStoppedRS->Draw("histo");
hPionMomentumNonStoppedBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg11 = new TLegend();
leg11 = new TLegend(0.58,0.65,0.88,0.88);
leg11->SetTextSize(0.04);
leg11->SetTextAlign(12);
leg11->SetFillColor(kWhite);
leg11->SetLineColor(kWhite);
leg11->SetShadowColor(kWhite);
leg11->SetHeader("SciBooNE MC");
leg11->AddEntry(hPionMomentumNonStoppedRS,"New R-S Model");
leg11->AddEntry(hPionMomentumNonStoppedBS,"New B-S Model");
leg11->Draw();
// =======================================================


// =======================================================
//             ### Non-Stopped Pion Angle ###
// =======================================================
TCanvas *c12 = new TCanvas("c12", "Non-Stopped Pion Angles");
c12->SetTicks();
c12->SetFillColor(kWhite);

// Area normalzing the plot 
hPionAngleNonStoppedBS->Scale(1/hPionAngleNonStoppedBS->Integral());
hPionAngleNonStoppedRS->Scale(1/hPionAngleNonStoppedRS->Integral());

hPionAngleNonStoppedRS->SetLineColor(kBlue);
hPionAngleNonStoppedRS->SetLineWidth(2);

hPionAngleNonStoppedBS->SetLineColor(kRed);
hPionAngleNonStoppedBS->SetLineWidth(2);

hPionAngleNonStoppedBS->GetXaxis()->SetTitle("Pion Angle (Degrees)");
hPionAngleNonStoppedBS->GetXaxis()->CenterTitle();

hPionAngleNonStoppedBS->GetYaxis()->SetTitle("Normalized Events (/ 4.5Degrees)");
hPionAngleNonStoppedBS->GetYaxis()->CenterTitle();

hPionAngleNonStoppedBS->Draw("histo");
hPionAngleNonStoppedRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg12 = new TLegend();
leg12 = new TLegend(0.58,0.65,0.88,0.88);
leg12->SetTextSize(0.04);
leg12->SetTextAlign(12);
leg12->SetFillColor(kWhite);
leg12->SetLineColor(kWhite);
leg12->SetShadowColor(kWhite);
leg12->SetHeader("SciBooNE MC");
leg12->AddEntry(hPionAngleNonStoppedRS,"New R-S Model");
leg12->AddEntry(hPionAngleNonStoppedBS,"New B-S Model");
leg12->Draw();
// =======================================================

// #######################################################
}
