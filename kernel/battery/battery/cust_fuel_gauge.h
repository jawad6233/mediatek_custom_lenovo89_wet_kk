#include <mach/mt_typedefs.h>

#define TEMPERATURE_T0                  110
#define TEMPERATURE_T1                  0
#define TEMPERATURE_T2                  25
#define TEMPERATURE_T3                  50
#define TEMPERATURE_T                   255 // This should be fixed, never change the value

#define FG_METER_RESISTANCE 	0

#define MAX_BOOTING_TIME_FGCURRENT	1*10 // 10s

#if defined(CONFIG_POWER_EXT)
#define OCV_BOARD_COMPESATE	72 //mV 
#define R_FG_BOARD_BASE		1000
#define R_FG_BOARD_SLOPE	1000 //slope
#else
#define OCV_BOARD_COMPESATE	0 //mV 
#define R_FG_BOARD_BASE		1000
#define R_FG_BOARD_SLOPE	1000 //slope
#endif

#define Q_MAX_POS_50	4180
#define Q_MAX_POS_25	4187
#define Q_MAX_POS_0		4104
#define Q_MAX_NEG_10	3784

#define Q_MAX_POS_50_H_CURRENT	4100
#define Q_MAX_POS_25_H_CURRENT	4110
#define Q_MAX_POS_0_H_CURRENT	  3929
#define Q_MAX_NEG_10_H_CURRENT	3055

#define R_FG_VALUE 				20 // mOhm, base is 20
#define CURRENT_DETECT_R_FG	10  //1mA

#define OSR_SELECT_7			0

#define CAR_TUNE_VALUE			87 //1.00

/////////////////////////////////////////////////////////////////////
// <DOD, Battery_Voltage> Table
/////////////////////////////////////////////////////////////////////
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
{	0	,	4324	},
{	2	,	4309	},
{	3	,	4289	},
{	4	,	4271	},
{	6	,	4254	},
{	7	,	4237	},
{	9	,	4221	},
{	10	,	4205	},
{	12	,	4189	},
{	13	,	4173	},
{	15	,	4158	},
{	16	,	4142	},
{	18	,	4126	},
{	19	,	4110	},
{	21	,	4095	},
{	22	,	4081	},
{	24	,	4069	},
{	25	,	4055	},
{	27	,	4036	},
{	28	,	4016	},
{	30	,	3997	},
{	31	,	3980	},
{	33	,	3965	},
{	34	,	3953	},
{	36	,	3943	},
{	37	,	3933	},
{	39	,	3923	},
{	40	,	3914	},
{	42	,	3904	},
{	43	,	3895	},
{	45	,	3886	},
{	46	,	3876	},
{	48	,	3868	},
{	49	,	3859	},
{	51	,	3851	},
{	52	,	3843	},
{	54	,	3835	},
{	55	,	3828	},
{	57	,	3821	},
{	58	,	3814	},
{	60	,	3808	},
{	61	,	3802	},
{	63	,	3795	},
{	64	,	3790	},
{	66	,	3784	},
{	67	,	3779	},
{	69	,	3775	},
{	70	,	3771	},
{	72	,	3768	},
{	73	,	3764	},
{	75	,	3761	},
{	76	,	3757	},
{	78	,	3754	},
{	79	,	3750	},
{	81	,	3746	},
{	82	,	3742	},
{	84	,	3738	},
{	85	,	3734	},
{	87	,	3730	},
{	88	,	3726	},
{	90	,	3721	},
{	91	,	3716	},
{	93	,	3711	},
{	94	,	3704	},
{	95	,	3700	},
{	96	,	3699	},
{	97	,	3697	},
{	97	,	3695	},
{	98	,	3694	},
{	98	,	3693	},
{	99	,	3692	},
{	99	,	3692	},
{	99	,	3690	},
{	100	,	3689	},
{	100	,	3689	},
{	100	,	3689	},
{	100	,	3689	},
{	100	,	3689	},
{	100	,	3689	},
{	100	,	3689	},
{	100	,	3689	}
};      
        
// T1 0C 
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{
{	0	,	4331	},
{	1	,	4312	},
{	3	,	4293	},
{	4	,	4276	},
{	6	,	4259	},
{	7	,	4243	},
{	8	,	4227	},
{	10	,	4212	},
{	11	,	4196	},
{	12	,	4181	},
{	14	,	4167	},
{	15	,	4152	},
{	17	,	4138	},
{	18	,	4122	},
{	19	,	4107	},
{	21	,	4094	},
{	22	,	4081	},
{	23	,	4069	},
{	25	,	4055	},
{	26	,	4039	},
{	28	,	4020	},
{	29	,	4003	},
{	30	,	3989	},
{	32	,	3975	},
{	33	,	3963	},
{	34	,	3951	},
{	36	,	3940	},
{	37	,	3929	},
{	39	,	3918	},
{	40	,	3907	},
{	41	,	3897	},
{	43	,	3887	},
{	44	,	3877	},
{	45	,	3868	},
{	47	,	3860	},
{	48	,	3852	},
{	50	,	3845	},
{	51	,	3838	},
{	52	,	3832	},
{	54	,	3825	},
{	55	,	3819	},
{	57	,	3813	},
{	58	,	3808	},
{	59	,	3804	},
{	61	,	3798	},
{	62	,	3794	},
{	63	,	3789	},
{	65	,	3785	},
{	66	,	3781	},
{	68	,	3778	},
{	69	,	3775	},
{	70	,	3772	},
{	72	,	3769	},
{	73	,	3766	},
{	74	,	3763	},
{	76	,	3760	},
{	77	,	3756	},
{	79	,	3752	},
{	80	,	3748	},
{	81	,	3743	},
{	83	,	3739	},
{	84	,	3733	},
{	85	,	3726	},
{	87	,	3719	},
{	88	,	3711	},
{	90	,	3703	},
{	91	,	3697	},
{	92	,	3692	},
{	94	,	3685	},
{	95	,	3677	},
{	96	,	3664	},
{	98	,	3636	},
{	99	,	3596	},
{	100	,	3576	},
{	100	,	3576	},
{	100	,	3576	},
{	100	,	3576	},
{	100	,	3576	},
{	100	,	3576	},
{	100	,	3576	},
{	100	,	3576	}
};           

// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
{	0	,	4333	},
{	1	,	4312	},
{	3	,	4293	},
{	4	,	4277	},
{	5	,	4260	},
{	7	,	4244	},
{	8	,	4228	},
{	9	,	4213	},
{	11	,	4197	},
{	12	,	4182	},
{	14	,	4167	},
{	15	,	4152	},
{	16	,	4137	},
{	18	,	4122	},
{	19	,	4108	},
{	20	,	4094	},
{	22	,	4081	},
{	23	,	4068	},
{	24	,	4055	},
{	26	,	4041	},
{	27	,	4027	},
{	28	,	4013	},
{	30	,	4001	},
{	31	,	3989	},
{	32	,	3978	},
{	34	,	3968	},
{	35	,	3958	},
{	36	,	3947	},
{	38	,	3935	},
{	39	,	3923	},
{	41	,	3908	},
{	42	,	3893	},
{	43	,	3881	},
{	45	,	3869	},
{	46	,	3861	},
{	47	,	3852	},
{	49	,	3845	},
{	50	,	3837	},
{	51	,	3831	},
{	53	,	3825	},
{	54	,	3819	},
{	55	,	3813	},
{	57	,	3809	},
{	58	,	3804	},
{	59	,	3800	},
{	61	,	3795	},
{	62	,	3791	},
{	64	,	3788	},
{	65	,	3784	},
{	66	,	3780	},
{	68	,	3777	},
{	69	,	3774	},
{	70	,	3771	},
{	72	,	3768	},
{	73	,	3763	},
{	74	,	3758	},
{	76	,	3752	},
{	77	,	3747	},
{	78	,	3742	},
{	80	,	3738	},
{	81	,	3732	},
{	82	,	3725	},
{	84	,	3717	},
{	85	,	3710	},
{	86	,	3703	},
{	88	,	3693	},
{	89	,	3686	},
{	91	,	3684	},
{	92	,	3681	},
{	93	,	3677	},
{	95	,	3666	},
{	96	,	3624	},
{	97	,	3560	},
{	99	,	3470	},
{	100	,	3470	},
{	100	,	3470	},
{	100	,	3470	},
{	100	,	3470	},
{	100	,	3470	},
{	100	,	3470	},
{	100	,	3470	}
};     

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
{	0	,	4339	},
{	1	,	4310	},
{	3	,	4292	},
{	4	,	4275	},
{	6	,	4258	},
{	7	,	4242	},
{	8	,	4226	},
{	10	,	4210	},
{	11	,	4194	},
{	12	,	4179	},
{	14	,	4164	},
{	15	,	4149	},
{	17	,	4134	},
{	18	,	4119	},
{	19	,	4105	},
{	21	,	4091	},
{	22	,	4077	},
{	23	,	4063	},
{	25	,	4050	},
{	26	,	4037	},
{	28	,	4024	},
{	29	,	4011	},
{	30	,	4000	},
{	32	,	3988	},
{	33	,	3977	},
{	34	,	3966	},
{	36	,	3955	},
{	37	,	3945	},
{	39	,	3934	},
{	40	,	3922	},
{	41	,	3907	},
{	43	,	3891	},
{	44	,	3878	},
{	46	,	3867	},
{	47	,	3858	},
{	48	,	3850	},
{	50	,	3842	},
{	51	,	3835	},
{	52	,	3828	},
{	54	,	3822	},
{	55	,	3816	},
{	57	,	3811	},
{	58	,	3806	},
{	59	,	3800	},
{	61	,	3796	},
{	62	,	3791	},
{	63	,	3788	},
{	65	,	3783	},
{	66	,	3780	},
{	68	,	3776	},
{	69	,	3773	},
{	70	,	3768	},
{	72	,	3759	},
{	73	,	3750	},
{	75	,	3744	},
{	76	,	3738	},
{	77	,	3733	},
{	79	,	3727	},
{	80	,	3723	},
{	81	,	3718	},
{	83	,	3713	},
{	84	,	3706	},
{	86	,	3699	},
{	87	,	3692	},
{	88	,	3685	},
{	90	,	3674	},
{	91	,	3670	},
{	92	,	3668	},
{	94	,	3665	},
{	95	,	3659	},
{	97	,	3637	},
{	98	,	3588	},
{	99	,	3520	},
{	100	,	3421	},
{	100	,	3421	},
{	100	,	3421	},
{	100	,	3421	},
{	100	,	3421	},
{	100	,	3421	},
{	100	,	3421	},
{	100	,	3421	}
};           

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};      

/////////////////////////////////////////////////////////////////////
// <Rbat, Battery_Voltage> Table
/////////////////////////////////////////////////////////////////////
typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
{	333	,	4324	},
{	388	,	4309	},
{	748	,	4289	},
{	748	,	4271	},
{	748	,	4254	},
{	748	,	4237	},
{	748	,	4221	},
{	750	,	4205	},
{	750	,	4189	},
{	750	,	4173	},
{	750	,	4158	},
{	753	,	4142	},
{	750	,	4126	},
{	750	,	4110	},
{	745	,	4095	},
{	743	,	4081	},
{	750	,	4069	},
{	758	,	4055	},
{	758	,	4036	},
{	753	,	4016	},
{	748	,	3997	},
{	743	,	3980	},
{	735	,	3965	},
{	730	,	3953	},
{	733	,	3943	},
{	733	,	3933	},
{	733	,	3923	},
{	730	,	3914	},
{	730	,	3904	},
{	733	,	3895	},
{	733	,	3886	},
{	733	,	3876	},
{	735	,	3868	},
{	740	,	3859	},
{	738	,	3851	},
{	738	,	3843	},
{	738	,	3835	},
{	740	,	3828	},
{	743	,	3821	},
{	748	,	3814	},
{	755	,	3808	},
{	755	,	3802	},
{	760	,	3795	},
{	763	,	3790	},
{	763	,	3784	},
{	765	,	3779	},
{	773	,	3775	},
{	775	,	3771	},
{	788	,	3768	},
{	798	,	3764	},
{	808	,	3761	},
{	818	,	3757	},
{	835	,	3754	},
{	848	,	3750	},
{	865	,	3746	},
{	878	,	3742	},
{	903	,	3738	},
{	928	,	3734	},
{	958	,	3730	},
{	995	,	3726	},
{	1033	,	3721	},
{	1085	,	3716	},
{	1150	,	3711	},
{	1218	,	3704	},
{	1250	,	3700	},
{	1248	,	3699	},
{	1245	,	3697	},
{	1240	,	3695	},
{	1238	,	3694	},
{	1235	,	3693	},
{	1230	,	3692	},
{	1230	,	3692	},
{	1225	,	3690	},
{	1223	,	3689	},
{	1223	,	3689	},
{	1223	,	3689	},
{	1223	,	3689	},
{	1223	,	3689	},
{	1223	,	3689	},
{	1223	,	3689	},
{	1223	,	3689	}
};      

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
{	228	,	4331	},
{	195	,	4312	},
{	310	,	4293	},
{	315	,	4276	},
{	315	,	4259	},
{	318	,	4243	},
{	323	,	4227	},
{	325	,	4212	},
{	328	,	4196	},
{	330	,	4181	},
{	335	,	4167	},
{	338	,	4152	},
{	343	,	4138	},
{	343	,	4122	},
{	343	,	4107	},
{	345	,	4094	},
{	345	,	4081	},
{	353	,	4069	},
{	355	,	4055	},
{	360	,	4039	},
{	355	,	4020	},
{	350	,	4003	},
{	350	,	3989	},
{	345	,	3975	},
{	343	,	3963	},
{	338	,	3951	},
{	335	,	3940	},
{	333	,	3929	},
{	330	,	3918	},
{	330	,	3907	},
{	330	,	3897	},
{	328	,	3887	},
{	323	,	3877	},
{	323	,	3868	},
{	323	,	3860	},
{	320	,	3852	},
{	323	,	3845	},
{	323	,	3838	},
{	325	,	3832	},
{	325	,	3825	},
{	325	,	3819	},
{	325	,	3813	},
{	328	,	3808	},
{	330	,	3804	},
{	330	,	3798	},
{	333	,	3794	},
{	333	,	3789	},
{	333	,	3785	},
{	333	,	3781	},
{	335	,	3778	},
{	338	,	3775	},
{	340	,	3772	},
{	345	,	3769	},
{	348	,	3766	},
{	353	,	3763	},
{	355	,	3760	},
{	360	,	3756	},
{	363	,	3752	},
{	370	,	3748	},
{	375	,	3743	},
{	383	,	3739	},
{	388	,	3733	},
{	398	,	3726	},
{	408	,	3719	},
{	420	,	3711	},
{	438	,	3703	},
{	465	,	3697	},
{	505	,	3692	},
{	558	,	3685	},
{	633	,	3677	},
{	735	,	3664	},
{	858	,	3636	},
{	990	,	3596	},
{	943	,	3576	},
{	943	,	3576	},
{	943	,	3576	},
{	943	,	3576	},
{	943	,	3576	},
{	943	,	3576	},
{	943	,	3576	},
{	943	,	3576	}
};     

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
{	138	,	4333	},
{	170	,	4312	},
{	173	,	4293	},
{	175	,	4277	},
{	175	,	4260	},
{	175	,	4244	},
{	175	,	4228	},
{	178	,	4213	},
{	180	,	4197	},
{	183	,	4182	},
{	183	,	4167	},
{	185	,	4152	},
{	185	,	4137	},
{	185	,	4122	},
{	190	,	4108	},
{	190	,	4094	},
{	193	,	4081	},
{	195	,	4068	},
{	195	,	4055	},
{	200	,	4041	},
{	203	,	4027	},
{	203	,	4013	},
{	205	,	4001	},
{	205	,	3989	},
{	208	,	3978	},
{	208	,	3968	},
{	205	,	3958	},
{	205	,	3947	},
{	200	,	3935	},
{	198	,	3923	},
{	190	,	3908	},
{	180	,	3893	},
{	178	,	3881	},
{	173	,	3869	},
{	178	,	3861	},
{	175	,	3852	},
{	175	,	3845	},
{	173	,	3837	},
{	175	,	3831	},
{	178	,	3825	},
{	178	,	3819	},
{	178	,	3813	},
{	183	,	3809	},
{	185	,	3804	},
{	185	,	3800	},
{	185	,	3795	},
{	188	,	3791	},
{	190	,	3788	},
{	190	,	3784	},
{	190	,	3780	},
{	190	,	3777	},
{	190	,	3774	},
{	190	,	3771	},
{	190	,	3768	},
{	190	,	3763	},
{	188	,	3758	},
{	183	,	3752	},
{	183	,	3747	},
{	180	,	3742	},
{	183	,	3738	},
{	183	,	3732	},
{	180	,	3725	},
{	178	,	3717	},
{	178	,	3710	},
{	183	,	3703	},
{	180	,	3693	},
{	180	,	3686	},
{	190	,	3684	},
{	198	,	3681	},
{	210	,	3677	},
{	223	,	3666	},
{	220	,	3624	},
{	240	,	3560	},
{	265	,	3470	},
{	670	,	3470	},
{	670	,	3470	},
{	670	,	3470	},
{	670	,	3470	},
{	670	,	3470	},
{	670	,	3470	},
{	670	,	3470	}
}; 

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
{	170	,	4339	},
{	150	,	4310	},
{	158	,	4292	},
{	158	,	4275	},
{	158	,	4258	},
{	160	,	4242	},
{	160	,	4226	},
{	158	,	4210	},
{	158	,	4194	},
{	158	,	4179	},
{	160	,	4164	},
{	160	,	4149	},
{	160	,	4134	},
{	160	,	4119	},
{	160	,	4105	},
{	163	,	4091	},
{	163	,	4077	},
{	163	,	4063	},
{	163	,	4050	},
{	165	,	4037	},
{	165	,	4024	},
{	163	,	4011	},
{	168	,	4000	},
{	168	,	3988	},
{	170	,	3977	},
{	173	,	3966	},
{	173	,	3955	},
{	175	,	3945	},
{	178	,	3934	},
{	180	,	3922	},
{	173	,	3907	},
{	165	,	3891	},
{	163	,	3878	},
{	163	,	3867	},
{	160	,	3858	},
{	160	,	3850	},
{	160	,	3842	},
{	160	,	3835	},
{	160	,	3828	},
{	160	,	3822	},
{	160	,	3816	},
{	163	,	3811	},
{	163	,	3806	},
{	160	,	3800	},
{	163	,	3796	},
{	163	,	3791	},
{	168	,	3788	},
{	165	,	3783	},
{	168	,	3780	},
{	168	,	3776	},
{	170	,	3773	},
{	170	,	3768	},
{	163	,	3759	},
{	160	,	3750	},
{	160	,	3744	},
{	160	,	3738	},
{	163	,	3733	},
{	160	,	3727	},
{	163	,	3723	},
{	163	,	3718	},
{	163	,	3713	},
{	163	,	3706	},
{	163	,	3699	},
{	163	,	3692	},
{	165	,	3685	},
{	160	,	3674	},
{	163	,	3670	},
{	168	,	3668	},
{	173	,	3665	},
{	178	,	3659	},
{	173	,	3637	},
{	178	,	3588	},
{	185	,	3520	},
{	190	,	3421	},
{	555	,	3421	},
{	555	,	3421	},
{	555	,	3421	},
{	555	,	3421	},
{	555	,	3421	},
{	555	,	3421	},
{	555	,	3421	}
}; 

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
  {0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 }, 
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },  
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 },
	{0  , 0 }
};      


int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);

//#define CONFIG_POWER_VERIFY
