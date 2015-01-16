#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>

//#include "msdk_nvram_camera_exp.h"
//#include "msdk_lens_exp.h"
#include "camera_custom_nvram.h"
#include "camera_custom_lens.h"

const NVRAM_LENS_PARA_STRUCT DW9718AF_LENS_PARA_DEFAULT_VALUE =
{
    //Version
    NVRAM_CAMERA_LENS_FILE_VERSION,

    // Focus Range NVRAM
    {0, 1023},

    // AF NVRAM
    {
        // ------------------------------ sAF_Coef -----------------------------------------
        {
            {
                180, // i4Offset
                16,  // i4NormalNum
                16,  // i4MacroNum
                1,   // i4InfIdxOffset
                1,   // i4MacroIdxOffset           
                {
                    0,  20,  45,  60,  75, 90, 115, 140, 180, 220,
                    255, 300, 355,   400,   500,   600,   0,   0,   0,   0,
                    0,	  0,	 0,    0,	 0,    0,	 0,    0,	 0,    0
                }
            },
            18, // i4THRES_MAIN;
            13, // i4THRES_SUB; 
            1,  // i4AFC_FAIL_CNT;             
            0,//0,//0,  // i4FAIL_POS;          
                            
            4,  // i4INIT_WAIT;
            {500, 500, 500, 500, 500}, // i4FRAME_WAIT
            0,  // i4DONE_WAIT;              
        },
        // ------------------------------- sVAFC_Coef --------------------------------------------
        {
            {
                180, // i4Offset
                16,  // i4NormalNum
                16,  // i4MacroNum
                1,   // i4InfIdxOffset
                1,   // i4MacroIdxOffset           
                {
                    0,  20,  45,  60,  75, 90, 115, 140, 180, 220,
                    255, 300, 355,   400,   500,   600,   0,   0,   0,   0,
                    0,	  0,	 0,    0,	 0,    0,	 0,    0,	 0,    0
                }
            },          
            18, // i4THRES_MAIN;
            13, // i4THRES_SUB;       
            1,  // i4AFC_FAIL_CNT;                      
            0,//0,//0,  // i4FAIL_POS;

            4,  // i4INIT_WAIT;
            {500, 500, 500, 500, 500}, // i4FRAME_WAIT
            0,  // i4DONE_WAIT;                  
        },
        // -------------------- sAF_TH ---------------------
        {
            8, // i4ISONum;
            {100,150,200,300,400,600,800,1600}, // i4ISO[ISO_MAX_NUM];
                  
            // SGG1~7
            {20, 19, 19, 18, 18, 17, 16, 15,
             29, 29, 28, 28, 27, 26, 26, 24,
             43, 42, 42, 41, 41, 40, 39, 37,
             62, 61, 61, 60, 60, 59, 58, 56,
             88, 88, 88, 87, 87, 86, 85, 84,
             126, 126, 126, 125, 125, 125, 124, 123,
             180, 180, 180, 179, 179, 179, 179, 178},
      
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];

            {7000,7000,7000,7000,7000,7000,7000,7000}, // i4MIN_TH[ISO_MAX_NUM];

            {3, 4, 4, 4, 5, 5, 5, 5}, // i4HW_TH[ISO_MAX_NUM];

            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];

            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];

            {4, 4, 4, 5, 5, 5, 6, 6} // i4HW_TH2[ISO_MAX_NUM];
        },
        // ------------------- sZSDAF_TH -----------------------------------
        {
            8, // i4ISONum;
            {100,150,200,300,400,600,800,1600}, // i4ISO[ISO_MAX_NUM];
                   
            // SGG1~7
            {20, 19, 19, 18, 18, 17, 16, 15,
             29, 29, 28, 28, 27, 26, 26, 24,
             43, 42, 42, 41, 41, 40, 39, 37,
             62, 61, 61, 60, 60, 59, 58, 56,
             88, 88, 88, 87, 87, 86, 85, 84,
             126, 126, 126, 125, 125, 125, 124, 123,
             180, 180, 180, 179, 179, 179, 179, 178},
                         
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];

            {10000,10000,10000,10000,10000,9000,9000,9000}, // i4MIN_TH[ISO_MAX_NUM];       

            {6, 7, 8, 9, 10, 13, 14, 21}, // i4HW_TH[ISO_MAX_NUM];

            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];

            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];

            {9, 11, 13, 15, 17, 20, 26, 40} // i4HW_TH2[ISO_MAX_NUM];
        },
        // -------------------- sVID_AF_TH ---------------------
        {
            0,             
        },
        // -------------------- sIHDR_AF_TH ---------------------
        {
            0,              
        },
        // -------------------- sREV1_AF_TH ---------------------
        {
            0,                
        },
        // -------------------- sREV2_AF_TH ---------------------
        {
            0,                 
        },

        // --- Common use ---
        1,  // i4ReadOTP; 				// 0: disable, 1:enable           
        3,  // i4StatGain;    
        0,  // i4LV_THRES;
        225,// i4InfPos;
        33, // i4FRAME_TIME                            
        {0, 100, 200, 350, 500}, // back jump
        500,//i4BackJumpPos

        20, // i4AFC_STEP_SIZE;     
        18, // i4SPOT_PERCENT_W;        // AFC window location
        24, // i4SPOT_PERCENT_H;        // AFC window location
        0,  // i4CHANGE_CNT_DELTA;    
        
        1,  // i4AFS_STEP_MIN_ENABLE;
        4,  // i4AFS_STEP_MIN_NORMAL;
        4,  // i4AFS_STEP_MIN_MACRO;
    
        5,  // i4FIRST_FV_WAIT;            
        10, // i4FV_1ST_STABLE_THRES;        
        100,// i4FV_1ST_STABLE_OFFSET;
        15, // i4FV_1ST_STABLE_NUM;                        
        12, // i4FV_1ST_STABLE_CNT; 
        50, // i4FV_SHOCK_THRES;
        30000, // i4FV_SHOCK_OFFSET;
        5,  // i4FV_VALID_CNT;
        20, // i4FV_SHOCK_FRM_CNT;
        5,  // i4FV_SHOCK_CNT; 
        
        // --- FaceAF ---
        80, // i4FDWinPercent;
        20, // i4FDSizeDiff;
	    15, // i4FD_DETECT_CNT;
	    5,  // i4FD_NONE_CNT;  
              
        // --- AFv1.1/AFv1.2 ---
        0,  // i4LeftSearchEnable;       //[0] 0:disable, 1:enable
        1,  // i4LeftJumpStep;           //[1] when disable left peak search, left step= 3 + i4LeftJumpStep
        0,  // No use
        0,  // i4AfDoneDelay;            //[3] AF done happen delay count
        0,  // i4VdoAfDoneDelay;         //[3] AF done happen delay count
        0,  // i4ZoomInWinChg;           //[4] enable AF window change with Zoom-in  
        1,  // i4SensorEnable;           //[5] AF use sensor lister => 0:disable, 1:enable
        95, // i4PostureComp;            //[6] post comp max offset => 0:disable, others:enable
        2,  // i4SceneMonitorLevel;      //[7] scenechange enhancement level => 0:original, 1~3:from stable to sensitive
        1,  // i4VdoSceneMonitorLevel;   //[7] scenechange enhancement level => 0:original, 1~3:from stable to sensitive

        // Scene Monitor 
        // {Type, Off, Thr{by level}, Cnt{by level}}        
        // Type: 1 is &&, 0 is ||
        // Off : value, min=0 is more sensitive
        // Thr : percentage(value for gyro/acce), min=0 is more sensitive 
        // Cnt : value, max=30 is more stable
        // preview params
        {1,                                       // FV 0:disable, 1:enable
         0,  100, { 40, 15, 20}, { 13, 3, 5},   //    chg; chgT lower to sensitive, chgN bigger to stable   //base on AF not with AE 
         1,1000, { 15, 15, 15}, { 20, 3, 8} }, //    stb; stbT should fix, stbN bigger to stable         
        {1,                                       // GS 0:disable, 1:enable
         0,   15, { 20, 15, 15}, { 28, 20, 15},   //    chg; chgT lower to sensitive, chgN bigger to stable
         1,    5, {  5,  5,  5}, { 12, 10,  7} }, //    stb  
        {1,                                       // AEB 0:disable, 1:enable
         0,   15, { 30, 30, 25}, { 40, 35, 25},   //    chg
         1,    5, { 2, 2, 2}, { 20, 16,  7} }, //    stb           
        {1,                                       // GYRO 0:disable, 1:enable
         0,    0, { 40, 30, 15}, {  5,  4,  3},   //    chg; off=0
         1,    0, { 10, 35, 8}, { 12, 3,  3} }, //    stb; off=0         
        {1,                                       // ACCE 0:disable, 1:enable
         0,    0, { 80, 40,18}, { 15,3, 3},   //    chg; off=0   
         1,    0, { 50, 40, 25}, { 12, 3,  3} }, //    stb; off=0      
        // video params
        {1,                                       // vdo FV
         0,  100, { 40, 40, 30}, { 13, 10, 10},   //    chg; chgT lower to sensitive, chgN bigger to stable   
         1, 5000, { 15, 15, 15}, { 20, 15, 10} }, //    stb; stbT should fix, stbN bigger to stable         
        {1,                                       // vdo GS
         0,   15, { 20, 20, 15}, { 28, 25, 25},   //    chg; chgT lower to sensitive, chgN bigger to stable
         1,    5, {  5,  5,  5}, { 15, 13, 10} }, //    stb            
        {1,                                       // vdo AEB
         0,   15, { 30, 30, 25}, { 33, 30, 30},   //    chg
         1,    5, { 10, 10, 10}, { 15, 13, 10} }, //    stb            
        {1,                                       // vdo GYRO
         0,    0, { 40, 40, 20}, {  7,  5,  5},   //    chg; video mode cnt > normal mode cnt for stable
         1,    0, { 10, 10, 10}, { 15, 13, 10} }, //    stb; video mode cnt > normal mode cnt for stable  
        {1,                                       // vdp ACCE 
         0,    0, { 80, 80, 60}, { 15, 12, 12},   //    chg; video mode cnt > normal mode cnt for stable  
         1,    0, { 50, 50, 50}, { 13, 13, 10} }, //    stb; video mode cnt > normal mode cnt for stable  

        // --- AFv2.0 ---     
        1,  // i4FvExtractEnable;           // 0:disable, 1:enable (for faceAF)
        30, // i4FvExtractThr               // percentage, fixed
        
        1,  // i4DampingCompEnable;         // 0:disable, 1:enable
        {8, 17, 25, 34, 43, 51, 60, 68, 77, 86},        // { step1, step2, ... , step 15(atmost) }
        {
            {  0,  0,  0,  0,  0,  0},// prerun0:{rComp1, rComp2, ..., rComp15(atmost)}
            {  0,  0,  0,  0,  0,  0}   // prerun1:{rComp1, rComp2, ..., rComp15(atmost)}
        }, 
        {
            {  0,  0,  0,  0,  0,  0},// prerun0:{lComp1, lComp2, ..., lComp15(atmost)}
            {  0,  0,  0,  0,  0,  0}   // prerun1:{lComp1, lComp2, ..., lComp15(atmost)}
        },
        
        1,  // i4DirSelectEnable;           // 0:disable, 1:enable
        -1, // i4InfDir;                    // 1:right, -1:left, 2:reverse, 0:keep
        -1, // i4MidDir;                    // "
        -1, // i4MacDir;                    // "
        40, // i4RatioInf;                  // below % of tableLength belongs to INF
        70, // i4RatioMac;                  // above % of tableLength belongs to MAC ; should be larger than i4RatioInf                
        0,  // i4StartBoundEnable;          // 0:disable, 1:enable
        3,  // i4StartCamCAF;               // 0:keep current, -1:force to INF, X:set to boundary if within X steps
        3,  // i4StartCamTAF;               // "
        0,  // i4StartVdoCAF;               // "
        0,  // i4StartVdoTAF;               // "                          
        1,  // i4FpsRemapTblEnable;         // 0:disable, 1:enable
        {10, 12}, // i4FpsThres[2];        // two fps threshold {very-low, low}
        {1, 0},   // i4TableClipPt[2];     // clip pts at macro side
        {80, 90}, // i4TableRemapPt[2];    // percentage of new/org table length

        // --- Easytuning ---       
        {0}, // i4EasyTuning[100]

       // --- DepthAF ---          
        {
     12,
     100,
     10,
     30, 70, 100, 
     1, 100, 100, 100, 0, -2, 0, 1, -1, -3, -1, -3, -1, -2, 1, 1, 1, 4, 6, 1, 2, 3, 2, 1,     
     2, 100, 100, 100, -5, -9, -7, -22, -25, -33, -28, -32, -57, -58, 5, 7, 16, 18, 31, 43, 40, 5, 31, 53,     
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     
     4, 100, 100, 100, -7, -11, -17, -21, -30, -36, -29, -43, -58, -55, 4, 10, 15, 22, 28, 26, 43, 34, 38, 21,     
     5, 100, 100, 100, -5, -8, -13, -16, -24, -28, -23, -34, -46, -44, 3, 8, 12, 17, 22, 20, 34, 27, 30, 16,     
     6, 100, 100, 100, -4, -6, -10, -13, -20, -23, -19, -28, -38, -36, 2, 6, 10, 14, 18, 16, 28, 22, 25, 13,     
     7, 100, 100, 100, -3, -5, -8, -11, -17, -19, -16, -24, -32, -30, 1, 5, 8, 12, 15, 13, 24, 18, 21, 11,     
     8, 100, 100, 100, -2, -4, -7, -9, -14, -16, -14, -21, -28, -26, 0, 4, 7, 10, 13, 11, 21, 15, 18, 9,     
     9, 100, 100, 100, -1, -3, -6, -8, -12, -14, -12, -18, -24, -23, 0, 3, 6, 8, 11, 9, 18, 13, 16, 8,     
     10, 100, 100, 100, 0, -2, -5, -7, -10, -12, -10, -16, -21, -20, 0, 2, 5, 7, 9, 8, 16, 11, 14, 7,     
     11, 100, 100, 100, 0, -1, -4, -6, -9, -10, -9, -14, -19, -18, 0, 1, 4, 6, 8, 7, 14, 10, 12, 6,     
     12, 100, 100, 100, 0, 0, -3, -5, -8, -9, -8, -12, -17, -16, 0, 0, 3, 5, 7, 6, 12, 9, 11, 5,
}, // i4DepthAF[500]
        
        // --- reserved ---                 
        { 
            // i4Coefs[0]  inclinePeak rejection;   0: is disable, 1: is enable
            // i4Coefs[1]  fdOffMaxCnt;             fd turnOff maxCnt for exiting faceAF, 0: use default value 10               
	        // i4Coefs[41]  isPLenable;             0: is disable, 1: is enable
	        // i4Coefs[42]  plFlashReject;          0: is default, 1: is reject PL when flash
	        // i4Coefs[43]  plThresNsLv;            lv for night scene 
	        // i4Coefs[44]  plThresIdLv;            lv for indoor
	        // i4Coefs[45]  plRatioNs;              ratio 0~100, from detect rate high to false alarm low
	        // i4Coefs[46]  plRatioId;              ratio 0~100, from detect rate high to false alarm low
	        // i4Coefs[47]  plRev1;
	        // i4Coefs[48]  plRev2;
	        // i4Coefs[49]  plRev3;
	        // i4Coefs[50]  plRev4;		
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    // [0]~[10]
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // [11]~[20]
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // [21]~[30]
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       // [31]~[40]              
            1, 0, 5,/*30,*/ 100, 80, 70, 0, 0, 0, 0,  // [41]~[50]
        }  // i4Coefs[100];
    },

    {0}
};


UINT32 DW9718AF_getDefaultData(VOID *pDataBuf, UINT32 size)
{
    UINT32 dataSize = sizeof(NVRAM_LENS_PARA_STRUCT);

    if ((pDataBuf == NULL) || (size < dataSize))
    {
        return 1;
    }

    // copy from Buff to global struct
    memcpy(pDataBuf, &DW9718AF_LENS_PARA_DEFAULT_VALUE, dataSize);

    return 0;
}

PFUNC_GETLENSDEFAULT pDW9718AF_getDefaultData = DW9718AF_getDefaultData;

