"""Lists of the variables that are stored by the base classes in Particles.h"""

basevars = ['P','PT','PE','PX','PY','PZ','M','MM','MMERR','ID','OWNPV_X','OWNPV_Y','OWNPV_Z','OWNPV_XERR','OWNPV_YERR','OWNPV_ZERR','OWNPV_CHI2','OWNPV_NDOF','OWNPV_COV_[3][3]','IP_OWNPV','IPCHI2_OWNPV','FD_OWNPV','FDCHI2_OWNPV','DIRA_OWNPV']

momvars = ['ENDVERTEX_X','ENDVERTEX_Y','ENDVERTEX_Z','ENDVERTEX_XERR','ENDVERTEX_YERR','ENDVERTEX_ZERR','ENDVERTEX_CHI2','ENDVERTEX_NDOF','ENDVERTEX_COV_[3][3]',]

kidvars = ['ORIVX_X','ORIVX_Y','ORIVX_Z','ORIVX_XERR','ORIVX_YERR','ORIVX_ZERR','ORIVX_CHI2','ORIVX_NDOF','ORIVX_COV_[3][3]','CosTheta','FD_ORIVX','FDCHI2_ORIVX','DIRA_ORIVX','PIDe','PIDmu','PIDK','PIDp']

intervars = kidvars[:-4] + momvars

eventvars = ['eventNumber','runNumber','nCandidate','totCandidates','EventInSequence','BCID','BCType','OdinTCK','L0DUTCK','HLT1TCK','HLT2TCK','GpsTime','Polarity','nPV','PVX[100]','PVY[100]','PVZ[100]','PVXERR[100]','PVYERR[100]','PVZERR[100]','PVCHI2[100]','PVNDOF[100]','PVNTRACKS[100]']
