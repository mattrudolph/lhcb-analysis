#!/usr/bin/env python

from ROOT import gROOT, TCanvas, TFile, TDirectory, TH1F, kBlue, kRed
gROOT.Macro("~/root/rootlogon.C")
f = TFile("test_jpsi.root")

c = TCanvas()


dsig = f.Get("Signal/Bs2stSelect_Sig")

dbkg_in_sig = f.Get("SameSignBG/Bs2stSelect_Sig")

dbkg = f.Get("SameSignBG/Bs2stSelect_Bkg")

for hkey in dsig.GetListOfKeys():

    hsig = hkey.ReadObj()
    hbkg_in_sig = dbkg_in_sig.Get(hkey.GetName())
    hbkg = dbkg.Get(hkey.GetName())

    hsig.Add( hbkg_in_sig, -1)
    
    hsig.Scale(1./hsig.Integral() )
    
    hbkg.Scale(1./hbkg.Integral() )

    hsig.SetLineColor(kBlue)
    hsig.SetMarkerColor(kBlue)

    hbkg.SetLineColor(kRed)
    hbkg.SetMarkerColor(kRed)
    

    hbkg.Draw()
    hsig.Draw("SAME")

    c.SaveAs("plots/"+hsig.GetName()+".png")
