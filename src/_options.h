#include "core_models.h"
#ifndef OPTIONS_H
#define OPTIONS_H

// isGammaRestoreOnCrashEnabled. When eqgame crashes, this restores your gamma. future EQ clients have this enabled.
// This also may fix eq trying to modify your gamma settings
bool isGammaRestoreOnCrashEnabled = true;

// isCpuSpeedFixEnabled is recommended to be false. Some CPUs have a symptom where the game runs too fast, future EQ clients have this enabled. There's a discussion on eqemu about a ryzen fix that's preferred over this.
bool isCpuSpeedFixEnabled = false;

// isMQInjectsEnabled if set to true will cause some edge-inspired features to work:
// MQ2Spawns, MQ2Maps, MQ2Commands, MQ2Pulse, MQ2Spawns, MapPlugin, MQ2ItemDisplay, MQ2Labels
// NOT RECOMMENDED. Known to cause memory leaks due to mq2maps strings
bool isMQInjectsEnabled = false;

// isMapWindowDisabled if set to true will do a soft patch to disable the map in game. If disabled, I suggest isMQInjectsEnabled being false as well, else npc data is still populated
bool isMapWindowDisabled = false;

// areLuclinModelsDisabled if set to true disables the ability for luclin models to load, forcing classic models
bool areLuclinModelsDisabled = false;

// isBazaarWindowDisabled if set to true will disable the bazaar window in game by doing a soft patch.
bool isBazaarWindowDisabled = false;

// isHeroicDisabled if set to true will make heroic stats not display
bool isHeroicDisabled = false;

// isMaxHPFixEnabled if set to true allows hp beyond 10 million, this is a rare situation for custom servers
// It also applies fixes where hp/mana/endurance state is more believed from server than client, this can cause strange status bar reports if client is out of sync
bool isMaxHPFixEnabled = false;

// isPatchmeDisabled if set to true will let you double click eqgame.exe and not get the "Please run EverQuest" message, will start properly
bool isPatchmeDisabled = true;

// isFoodDrinkSpamDisabled if set to true will stop you are hungry/thirsty messages to display on client. If server side isn't disabled, you can still get negative effects.
bool isFoodDrinkSpamDisabled = false;

// isMQ2PreventionEnabled if set to true will do basic prevention of mq2 by randomizing the version string, primitive anticheat
bool isMQ2PreventionEnabled = true;

// isSpellDataCRCEnabled if set to true will send spell data to the server as a CRC check, needs a server side modification not yet supported by eqemu master
bool isSpellDataCRCEnabled = false;

// isCombatDamageDoubleAppliedFixEnabled if set to true fixes a bug in rof2 where combat damage applied to client state is applied twice.
// it is the main cause of players falling unconsious while the server still thinks they're alive
// also can help with bouncing healthbar issues
bool isCombatDamageDoubleAppliedFixEnabled = true;

// isChecksumFixEnabled if set to true will override the normal checksum logic, if your server is not supporting checksums, can be left false
bool isChecksumFixEnabled = false;

// isOldModelHorseSupportEnabled if set to true enables horses while using old models
// quality of life for those that don't enjoy Luclin models but want their benefits
bool isOldModelHorseSupportEnabled = false;

// Allows classic and Luclin elementals to load simultaneously as race IDs 75 (classic) and 209-212 (Luclin)
bool isAllowAllElementalsEnabled = true;

// Allows classic skeleton (race 60) to use texture IDs beyond 0
bool isAllowBrownSkeletonsEnabled = true;

/*
isReportHardwareAddressEnabled if set to true will inspect mac addresses and send a more informative context of where EQ is running.
This requires custom server side code that is not in eqemu master branch, and in majority of cases can be left false

Add the following struct to "/common/eq_packets_structs.h"

struct MacEntry_Struct {
    BYTE address[8];
};

add to "/world/client.cpp", Client::HandlePacket, case OP_World_Client_CRC1:

case OP_World_Client_CRC1:
{
    if (app->size == sizeof(MacEntry_Struct)) {
        //Code to handle the MacEntry_Struct.
    }
}
*/
bool isReportHardwareAddressEnabled = true;

// isAllowIllegalAugmentsEnabled if set to true will allow inserting augments which create combinations that the player cannot use.
// This allows you to bypass an error of "The result of this combine would be both NO TRADE and unusable by you.". If you don't get this error, unlikely needed.
bool isAllowIllegalAugmentsEnabled = false;

// ***** NPC *******

// areCustomNPCsEnabled if set to true will allow the NPCs defined in NPCs[] to be injected in game
bool areCustomNPCsEnabled = false;

// NPC Entry:
// raceID is the index. If it's a new NPC, start at 733. You'll need to update the rule NPC:MaxRaceID
// GenderID ranges from 0 to 2 usually
// modelName is the race's shortname tag
// raceMask is a range of flags, typically using 8 is safe for most NPCs, but e.g. 1 = drivable boat, 2 = ridable boat, etc
// dbStrID if left to 1 reverts to raceID as it's ID, otherwise you can custom set one, and it'll look up dbStr for info
static NPCEntry NPCs[] = {
    // raceID, genderID, modelName, raceMask, dbStrID
    NPCEntry(733, 2, "SHI", 3, 1),
};

// areCustomAnimationsEnabled if set to true will allow custom animations defined in Animations[] to be injected in game
// NOTE: Must be exactly 2 or 3 characters long, e.g. "BET" or "OK", if only 2 characters, it will replace the first 2 characters of the animation
bool areCustomOldAnimationsEnabled = false;
static AnimationEntry CustomAnimations[] = {
    // originalName, replacementName
    AnimationEntry("DA", "DW"),
    //AnimationEntry("OK", "EL"),
};

// ***** ZONE *******

// areCustomZonesEnabled if set to true will allow custom zones defined in Zones[] to be injected in game (or replaced)
bool areCustomZonesEnabled = true;

static ZoneEntry Zones[] = {
    // zoneType, zoneID, zoneShortName, zoneLongName, eqStrID, zoneFlags2, x, y, z
    ZoneEntry(0, 1, "qeynos", "Southern Newport", 2243, 4, 0, 0, 0),
    ZoneEntry(0, 2, "qeynos2", "Northern Newport", 2244, 4, 0, 0, 0),
    ZoneEntry(0, 3, "qrg", "Surefall Glade", 2245, 4, 0, 0, 0),
    ZoneEntry(0, 4, "qeytoqrg", "Centaur Hills", 2246, 4, 0, 0, 0),
    //ZoneEntry(0, 5, "kingpass", "King\'s Pass", 2247, 4, 0, 0, 0),
    ZoneEntry(0, 5, "oldpass", "King\'s Pass", 2247, 4, 0, 0, 0),
    ZoneEntry(0, 6, "highkeep", "High Keep", 2248, 4, 0, 0, 0),
    ZoneEntry(0, 8, "freportn", "North Freeport", 2249, 4, 0, 0, 0),
    ZoneEntry(0, 9, "freportw", "West Freeport", 2250, 4, 0, 0, 0),
    ZoneEntry(0, 10, "freporte", "East Freeport", 2251, 4, 0, 0, 0),
    ZoneEntry(0, 11, "runnyeye", "The Runnyeye Citadel", 2252, 4, 0, 0, 0),
    ZoneEntry(0, 12, "qey2hh1", "Western Badlands", 2253, 4, 0, 0, 0),
    ZoneEntry(0, 13, "northkarana", "Northern Badlands", 2254, 4, 0, 0, 0),
    ZoneEntry(0, 14, "southkarana", "Southern Badlands", 2255, 4, 0, 0, 0),
    ZoneEntry(0, 15, "eastkarana", "Eastern Badlands", 2256, 4, 0, 0, 0),
    ZoneEntry(0, 16, "beholder", "Gorge of the One-Eye", 2257, 4, 0, 0, 0),
    ZoneEntry(0, 17, "blackburrow", "Blackburrow", 2258, 4, 0, 0, 0),
    ZoneEntry(0, 18, "paw", "Lair of Paw", 2259, 4, 0, 0, 0),
    ZoneEntry(0, 19, "rivervale", "Rivervale", 2260, 4, 0, 0, 0),
    ZoneEntry(0, 20, "kithicor", "Shadowdale", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 21, "commons", "Western Plaguelands", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 22, "ecommons", "Eastern Plaguelands", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 23, "erudnint", "Erudin Palace", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 24, "erudnext", "Erudin", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 25, "nektulos", "The Darkwoods", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 26, "cshome", "Sunset Home", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 27, "lavastorm", "Red Sun Peaks", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 29, "halas", "Halas", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 30, "everfrost", "Everfrost", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 31, "soldunga", "Red Sun Mines", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 32, "soldungb", "Fire Grottos", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 33, "misty", "Whisperling Forest", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 34, "nro", "Northern Waste of Tarhyl", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 35, "sro", "Southern Waste of Tarhyl", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 36, "befallen", "Halls of Misery", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 37, "oasis", "The Oasis", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 38, "tox", "Mistwoods", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 39, "hole", "Ruins of First City", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 40, "neriaka", "Ruins of Nagthilian", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 41, "neriakb", "Ruins of Nagthilian", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 42, "neriakc", "Ruins of Nagthilian", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 43, "neriakd", "Haegra Malath", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 44, "najena", "Tunnels of Lasanth", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 45, "qcat", "Newport Sewers", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 46, "innothule", "Stinger\'s Bog", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 47, "feerrott", "Greenmist Jungle", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 48, "cazicthule", "Hidden Temple of Yaralith", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 49, "oggok", "Oggok", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 50, "rathemtn", "Obsidian Shard Mountains", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 51, "lakerathe", "Lake Starfall", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 52, "grobb", "Grobb", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 53, "aviak", "The Dream", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 54, "gfaydark", "Greater Faydark", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 55, "akanon", "Underhill", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 56, "steamfont", "Steamfont Mountains", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 57, "lfaydark", "Lesser Faydark", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 58, "crushbone", "Fearstone Keep", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 59, "mistmoore", "Eldenal\'s Mansion", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 60, "kaladima", "South Kaladim", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 61, "felwithea", "Athica", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 62, "felwitheb", "Athica Elven Quarters", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 63, "unrest", "Shrouded Island", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 64, "kedge", "Kedge Keep", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 65, "guktop", "Halls of Mielech", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 66, "gukbottom", "Keep of Mielech", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 67, "kaladimb", "North Kaladim", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 68, "butcher", "Goblin Skull Mountains", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 69, "oot", "Sea of Swords", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 70, "cauldron", "Cauldron of Dawn", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 71, "airplane", "Real men do not use levitate", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 72, "fearplane", "Requiem of Fear", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 73, "permafrost", "Everchill Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 74, "kerraridge", "Sadri Malath", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 75, "paineel", "Valley of Erimal", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 76, "hateplane", "Lilla\'s Manor", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 77, "arena", "The Arena", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 78, "fieldofbone", "Field of Bone", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 79, "warslikswood", "Forest of the Fallen", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 80, "soltemple", "The Temple of Elael", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 81, "droga", "The Bloodied Quarry", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 82, "cabwest", "West New Ikild", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 83, "swampofnohope", "The Murk", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 84, "firiona", "Prophet\'s Landing", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 85, "lakeofillomen", "Lake of Ill Omen", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 86, "dreadlands", "Dreadlands", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 87, "burningwood", "The Tears of Elael", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 88, "kaesora", "Kaesora", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 89, "sebilis", "Mielech\'s Lair", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 90, "citymist", "Yclist, The Veiled City", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 91, "skyfire", "Skyfire", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 92, "frontiermtns", "Breaking your immersion, Crashville!", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 93, "overthere", "Breaking your immersion, Crashville!", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 94, "emeraldjungle", "The Emerald Jungle", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 95, "trakanon", "The Remnants of Old Ikild", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 96, "timorous", "Zone of Disappointing Loot", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 97, "kurn", "The Spires of Saitha", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 98, "erudsxing", "Storm Sea", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 100, "stonebrunt", "Sundered Mountains", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 101, "warrens", "Warrens", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 102, "karnor", "Citadel of the Claw", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 103, "chardok", "Tur`Ruj", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 104, "dalnir", "Silent Halls", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 105, "charasis", "Breaking your immersion, Crashville!", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 106, "cabeast", "East New Ikild", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 107, "nurga", "Oggok Mines", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 108, "veeshan", "Breaking your immersion, Crashville!", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 109, "veksar", "Heartland Undercaverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 110, "iceclad", "Frosthorn Coast", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 111, "frozenshadow", "Dreadfang Spire", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 112, "velketor", "Sorcerer\'s Labyrinth", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 113, "kael", "Stormkeep", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 114, "skyshrine", "Prison of Admyrrza", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 115, "thurgadina", "City of Thurgadin", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 116, "eastwastes", "Eastern Wastelands", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 117, "cobaltscar", "Wyvernfang Coast", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 118, "greatdivide", "Great Divide", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 119, "wakening", "Faentharc Woods", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 120, "westwastes", "Western Wastelands", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 121, "crystal", "Crystal Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 123, "necropolis", "Dragon Necropolis", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 124, "templeveeshan", "Dragonhorn Keep", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 125, "sirens", "Sirens Grotto", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 126, "mischiefplane", "Plain of Misscheef", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 127, "growthplane", "Plane of Earth", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 128, "sleeper", "Storm\'s Eye", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 129, "thurgadinb", "Icewell Keep", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 150, "shadowhaven", "Haven of Lore", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 151, "bazaar", "The Bazaar", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 152, "nexus", "The Nexus", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 153, "echo", "Echo Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 154, "acrylia", "Warpstone Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 155, "sharvahl", "Shar Vahl", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 156, "paludal", "The Abyss", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 157, "fungusgrove", "The Overgrowth", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 158, "vexthal", "Mansion of Portals", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 159, "sseru", "City of Mercy", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 160, "katta", "Taldor Malath", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 161, "netherbian", "Netherbian Lair", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 162, "ssratemple", "Cyrtho Malath", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 163, "griegsend", "Grieg\'s End", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 164, "thedeep", "The Deepshade", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 165, "shadeweaver", "Shadeweavers Thicket", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 166, "hollowshade", "RPGP, Tomb of the Ghost Writers", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 167, "grimling", "Haegra Malath", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 168, "mseru", "The Barrens", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 169, "letalis", "The Troll Zone", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 170, "twilight", "The Twilight Sea", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 171, "thegrey", "The Blight", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 172, "tenebrous", "RPGP, Trial of One Hundred Diggs", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 173, "maiden", "Spirit Valley", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 174, "dawnshroud", "Greenlight Hills", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 175, "scarlet", "The Scarlet Desert", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 176, "umbral", "The Silent Lands", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 179, "akheva", "Akhevan Ruins", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 181, "jaggedpine", "Heartland Plateau", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 182, "nedaria", "Nedaria\'s Landing", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 183, "tutorial", "Pocket Plane", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 184, "load", "The Eternal Well", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 186, "hateplaneb", "Requiem of Hate", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 187, "nektropos", "Shadowrest", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 188, "tutoriala", "The Mines of Gloomingdeep", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 189, "tutorialb", "The Dream", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 200, "codecay", "Ruins of Ixanvom", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 201, "pojustice", "Plane of Justice", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 202, "poknowledge", "The House", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 203, "potranquility", "Plane of Tranquility", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 204, "ponightmare", "Plane of Nightmare", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 205, "podisease", "Plane of Entropy", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 206, "poinnovation", "The Rust", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 207, "potorment", "Towers of Agony", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 208, "povalor", "House of Coding Horrors", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 209, "bothunder", "Thazeran\'s Tower", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 210, "postorms", "Plane of Storms", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 211, "hohonora", "Plane of Valor", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 212, "solrotower", "Tower of Tarhyl", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 213, "powar", "Plane of War", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 214, "potactics", "Plane of Tactics", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 215, "poair", "Plane of Air", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 216, "powater", "Caverns of the Deep One", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 217, "pofire", "Azzerach, the Forsaken Realm", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 218, "poeartha", "Plane of Earth", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 219, "potimea", "That One Place", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 220, "hohonorb", "Stronghold of Enthann", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 221, "nightmareb", "The Dream", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 222, "poearthb", "Plane of Earth", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 223, "potimeb", "Plane of Time", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 224, "gunthak", "Leaga Malath", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 225, "dulak", "Twilight Harbor", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 226, "torgiran", "Windstone Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 227, "nadox", "Breaking your immersion, Crashville!", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 228, "arttest", "Hate\'s Fury,The Scorned Maiden", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 229, "guka", "Mielech\'s Laboratory", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 230, "ruja", "Goldleaf Glen", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 231, "taka", "Taco Town", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 232, "mira", "The Silent Gallery", 2324, 4, 0, 0, 0),
    //ZoneEntry(0, 233, "mmca", "The Forlorn Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 233, "bleak", "Bleak Blind", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 234, "gukb", "The Drowning Crypt", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 235, "rujb", "Zenn Malath", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 236, "takb", "The Shifting Tower", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 237, "mirb", "Zone Connect", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 238, "mmcb", "The Dreary Grotto", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 239, "gukc", "The Ancient Aqueducts", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 240, "rujc", "The Scrap Heap", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 241, "takc", "The Fading Temple", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 242, "mirc", "The Spider Den", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 243, "mmcc", "Caverns of Darkness", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 244, "gukd", "The Mushroom Grove", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 245, "rujd", "The Gladiator Pits", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 246, "takd", "The Royal Observatory", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 247, "mird", "The Hushed Bankquet", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 248, "mmcd", "The Chambers of Eternal Afflictions", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 249, "guke", "Hollows of Underhill", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 250, "ruje", "Bloodstorm Tunnels", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 251, "take", "The River of Recollection", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 252, "mire", "Azmaen, The Heart of Frost", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 253, "mmce", "Sepulcher of Darkness", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 254, "gukf", "The Chapel of the Witnesses", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 255, "rujf", "Sunken Cathedral", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 256, "takf", "The Sandfall Corridors", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 257, "mirf", "The Forgotten Wastes", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 258, "mmcf", "Catacombs of Elthannar", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 259, "gukg", "Grobb Undercity", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 260, "rujg", "The River of Recess", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 261, "takg", "The Balancing Chamber", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 262, "mirg", "The Heart of the Menagerie", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 263, "mmcg", "The Cesspits", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 264, "gukh", "The Accursed Sanctuary", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 265, "rujh", "The Blazing Forge", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 266, "takh", "The Ethereal Dojo", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 267, "mirh", "The Morbid Laboratory", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 268, "mmch", "The Aisles of Blood", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 269, "ruji", "The Arena of Chance", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 270, "taki", "The Antiquated Palace", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 271, "miri", "The Theater of Imprisoned Horror", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 272, "mmci", "The Halls of Sanguinary Rites", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 273, "rujj", "The Barracks of War", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 274, "takj", "The Prismatic Corridors", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 275, "mirj", "The Grand Athenaeum", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 276, "mmcj", "The Infernal Sanctuary", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 277, "chardokb", "The Halls of Betrayal", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 278, "soldungc", "Emberflow Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 280, "natimbi", "Natimbi, The Broken Shores ", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 281, "qinimi", "Boring Zone No One Cares About", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 282, "riwwi", "Riwwi, Coliseum of Games", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 283, "barindu", "Barindu, Hanging Gardens", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 284, "ferubi", "Lzaefyn, Seekers\' Sanctuary", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 285, "snpool", "Sewers of Freeport: Cesspit of Plague", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 286, "snlair", "Sewers of Ikild", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 287, "snplant", "Sewers of Nihilia, Purifying Plant ", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 288, "sncrematory", "Sewers of Freeport: Accursed Charnel", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 289, "tipt", "The Mountain Crags of Tarhyl", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 290, "vxed", "Tanagra", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 291, "yxtta", "Yxtta, Pulpit of Exiles", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 292, "uqua", "Plane of Dead Gnomes", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 293, "kodtaz", "The Lands of Mist", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 294, "ikkinz", "Ikkinz, Antechamber of Destruction ", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 295, "qvic", "Qvic, Prayer Grounds of Calling", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 296, "inktuta", "Breaking your immersion, Crashville!", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 297, "txevu", "Txevu, Lair of the Elites", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 298, "tacvi", "Reghrat, Fortress of the Mistborn", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 300, "wallofslaughter", "Wall of Slaughter", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 301, "bloodfields", "The Bloodfields", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 302, "draniksscar", "Dranik\'s Scar", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 303, "causeway", "Nobles Causeway", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 304, "chambersa", "Muramite Proving Grounds", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 305, "chambersb", "Muramite Proving Grounds", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 306, "chambersc", "Muramite Proving Grounds", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 307, "chambersd", "Muramite Proving Grounds", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 308, "chamberse", "Muramite Proving Grounds", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 309, "chambersf", "Muramite Proving Grounds", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 316, "provinggrounds", "Muramite Proving Grounds", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 317, "anguish", "Asylum of Anguish", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 318, "dranikhollowsa", "Dranik\'s Hollows", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 319, "dranikhollowsb", "Dranik\'s Hollows", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 320, "dranikhollowsc", "Dranik\'s Hollows", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 328, "dranikcatacombsa", "The Morgue of Erudin", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 329, "dranikcatacombsb", "Catacombs of Dranik", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 330, "dranikcatacombsc", "Catacombs of Dranik", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 331, "draniksewersa", "Sewers of Dranik", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 332, "draniksewersb", "Sewers of Dranik", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 333, "draniksewersc", "Sewers of Dranik", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 334, "riftseekers", "Zone with Literally No Loot", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 335, "harbingers", "Harbingers\' Spire", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 336, "dranik", "The Ruined City of Dranik", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 349, "illsalinb", "Inner Tanagra", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 376, "takishruins", "Ruins of Takish-Hiz", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 377, "takishruinsa", "Sundered Caverns", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 384, "freeportsewers", "Filtration Chamber Six", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 406, "ashengate", "Breaking your immersion, Crashville!", 2324, 4, 0, 0, 0),
    ZoneEntry(0, 407, "highpass", "King\'s Pass", 2247, 4, 0, 0, 0),
    //ZoneEntry(0, 768, "bleak", "Bleak Burrows", 44444, 4, 0, 0, 0),

};
#endif
