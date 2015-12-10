#!/usr/bin/env python

from ROOT import gROOT,TFile,TDirectory,TCanvas,TH1F,kBlue,kRed

gROOT.Macro("~/rootlogon.C")

fs = TFile("bu2rhomunu.root")
dsig = fs.Get("Bu2RhoMuX_Tuple/RhoMuSelectModule")
fb = TFile("bu2rhomunu_data.root")
dbkg = fb.Get("Bs2st2BuK_RhoMuX_Tuple/RhoMuSelectModule")


c = TCanvas()


for hkey in dsig.GetListOfKeys():

    hsig = hkey.ReadObj()

    hbkg = dbkg.Get(hkey.GetName())

    
    hsig.Scale(1./hsig.Integral() )
    
    hbkg.Scale(1./hbkg.Integral() )

    hsig.SetLineColor(kBlue)
    hsig.SetMarkerColor(kBlue)

    hbkg.SetLineColor(kRed)
    hbkg.SetMarkerColor(kRed)
 

    hbkg.Draw()
    hsig.Draw("SAME")

    c.SaveAs("plots/"+hsig.GetName()+".png")

