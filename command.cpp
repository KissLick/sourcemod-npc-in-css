
#include "command.h"
#include "CAI_NPC.h"


ConVar *sv_gravity = NULL;
ConVar *phys_pushscale = NULL;
ConVar *npc_height_adjust = NULL;
ConVar *ai_path_adjust_speed_on_immediate_turns = NULL;
ConVar *ai_path_insert_pause_at_obstruction = NULL;
ConVar *ai_path_insert_pause_at_est_end = NULL;
ConVar *scene_flatturn = NULL;
ConVar *ai_use_clipped_paths = NULL;
ConVar *ai_moveprobe_usetracelist = NULL;
ConVar *ai_use_visibility_cache = NULL;
ConVar *ai_strong_optimizations = NULL;

ConVar *violence_hblood = NULL;
ConVar *violence_ablood = NULL;
ConVar *violence_hgibs = NULL;
ConVar *violence_agibs = NULL;

ConVar *sv_suppress_viewpunch = NULL;
ConVar *ai_navigator_generate_spikes = NULL;
ConVar *ai_navigator_generate_spikes_strength = NULL;

ConVar *ai_no_node_cache = NULL;
ConVar *sv_stepsize = NULL;
ConVar *hl2_episodic = NULL;
ConVar *ai_follow_use_points = NULL;
ConVar *ai_LOS_mode = NULL;
ConVar *ai_follow_use_points_when_moving = NULL;

ConVar *ammo_hegrenade_max = NULL;


void cmd1_CommandCallback(const CCommand &command)
{
	int client = g_Monster.GetCommandClient();
	if(client)
	{

	} else {
		Vector vec(501.0f,22.7f,70.21f);

		//vec.Init(6220.0f, 2813.0f, 1090.0f);

		//vec.Init(73.18,-54.81,-60.0);

		//vec.Init(952.65466,61.566082,-58.339985);


		//CEntity *cent = CreateEntityByName("npc_headcrab");
		/*CEntity *cent2 = CEntity::Instance(cbase2);
		cent2->Spawn();
		cent2->Teleport(&vec, NULL,NULL);

		CAI_NPC *hc2 = dynamic_cast<CAI_NPC *>(cent2);*/

		//CE_NPC_Headcrab *hc = dynamic_cast<CE_NPC_Headcrab *>(cent);

		//CEntity *cent = CreateEntityByName("npc_headcrab_fast");
		//CEntity *cent = CEntity::Instance(cbase);
		//CE_NPC_FastHeadcrab *hc = dynamic_cast<CE_NPC_FastHeadcrab *>(cent);

		//CEntity *cent = CreateEntityByName("npc_headcrab_black");
		//CEntity *cent = CEntity::Instance(cbase);
		//CE_NPC_BlackHeadcrab *hc = dynamic_cast<CE_NPC_BlackHeadcrab *>(cent);

		//CEntity *cent = CreateEntityByName("npc_fastzombie");
		//CEntity *cent = CreateEntityByName("npc_fastzombie_torso");
		//CEntity *cent = CreateEntityByName("npc_zombie_torso");
		CEntity *cent = CreateEntityByName("npc_zombie");
		//CEntity *cent = CreateEntityByName("npc_poisonzombie");
		
		//CEntity *cent = CreateEntityByName("npc_manhack");
		//CEntity *cent = CreateEntityByName("npc_antlionguard");

		//CEntity *cent = CreateEntityByName("npc_stalker");
		//CEntity *cent = CreateEntityByName("npc_antlion");

		//CEntity *cent = CreateEntityByName("npc_vortigaunt");

		//CEntity *cent = CreateEntityByName("npc_rollermine");
		
		//CEntity *cent = CreateEntityByName("npc_test");

		CBaseEntity *cbase = cent->BaseEntity();

		CAI_NPC *hc = dynamic_cast<CAI_NPC *>(cent);
		
		//DispatchSpawn(cbase);
		
		hc->Spawn();

		hc->SetMoveType(MOVETYPE_NONE);

		hc->Teleport(&vec, NULL,NULL);

		edict_t *pEdict = servergameents->BaseEntityToEdict(cbase);
		META_CONPRINTF("%p %d %d\n",cbase, cent->entindex_non_network(), engine->IndexOfEdict(pEdict));

	}
}

void cmd2_CommandCallback(const CCommand &command)
{
	for (int i=0;i<ENTITY_ARRAY_SIZE;i++)
	{
		CEntity *cent = CEntity::Instance(i);
		if(cent != NULL)
		{
			META_CONPRINTF("%s\n",cent->GetClassname());

		}
	}
}

void monster_dump_CommandCallback(const CCommand &command)
{
	GetEntityManager()->PrintDump();
}

#define GET_CONVAR(name) \
	name = g_pCVar->FindVar(#name); \
	if(name == NULL) { \
		META_CONPRINTF("[%s] %s - FAIL\n",g_Monster.GetLogTag(), #name); \
		return false; \
	}


bool CommandInitialize()
{
	//new ConCommand("e5",cmd1_CommandCallback, "", FCVAR_GAMEDLL);
	//new ConCommand("e6",cmd2_CommandCallback, "", FCVAR_GAMEDLL);
	new ConCommand("monster_dump",monster_dump_CommandCallback, "", FCVAR_GAMEDLL);

	GET_CONVAR(sv_gravity);
	GET_CONVAR(phys_pushscale);
	GET_CONVAR(npc_height_adjust);

	GET_CONVAR(ai_path_adjust_speed_on_immediate_turns);
	GET_CONVAR(ai_path_insert_pause_at_obstruction);
	GET_CONVAR(ai_path_insert_pause_at_est_end);
	GET_CONVAR(ai_use_clipped_paths);
	GET_CONVAR(ai_moveprobe_usetracelist);
	GET_CONVAR(scene_flatturn);

	GET_CONVAR(violence_hblood);
	GET_CONVAR(violence_ablood);
	GET_CONVAR(violence_hgibs);
	GET_CONVAR(violence_agibs);

	GET_CONVAR(sv_suppress_viewpunch);
	GET_CONVAR(ai_use_visibility_cache);
	GET_CONVAR(ai_strong_optimizations);
	GET_CONVAR(ai_navigator_generate_spikes);
	GET_CONVAR(ai_navigator_generate_spikes_strength);
	GET_CONVAR(ai_no_node_cache);

	GET_CONVAR(sv_stepsize);
	GET_CONVAR(hl2_episodic);
	GET_CONVAR(ai_follow_use_points);
	GET_CONVAR(ai_LOS_mode);
	GET_CONVAR(ai_follow_use_points_when_moving);

	GET_CONVAR(ammo_hegrenade_max);
	

	return true;
}
