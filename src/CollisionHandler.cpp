#include "CollisionHandler.h"
const int Cell_Size = 50;


void EnemyGameTile(GameObject& enemyObject,
	GameObject& staticGameTile)	{Virus& enemy = dynamic_cast<Virus&>(enemyObject);}

void BulletGameTile(GameObject& bull,
	GameObject& staticGameTile)
{

	Bullet& bullet = dynamic_cast<Bullet&>(bull);
	GameTile& Tile = dynamic_cast<GameTile&>(staticGameTile);
	bullet.setLife(true);

}

void BulletRock(GameObject& bull,
	GameObject& staticRock)
{
	Bullet& bullet = dynamic_cast<Bullet&>(bull);
	DarkTile& rock = dynamic_cast<DarkTile&>(staticRock);
	bullet.setLife(true);
}

void BulletDoor(GameObject& bull,
	GameObject& staticDoor)
{
	Bullet& bullet = dynamic_cast<Bullet&>(bull);
	Door& door = dynamic_cast<Door&>(staticDoor);
	bullet.setLife(true);
}
void BulletFire(GameObject& bull,
	GameObject& staticFire)
{
	Bullet& bullet = dynamic_cast<Bullet&>(bull);
	Fire& fire = dynamic_cast<Fire&>(staticFire);
	bullet.setLife(true);
}
	

void DaveAntidote(GameObject& Dave,
	GameObject& AntidoteObject)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);
	gamePlayer.setAntidote(true);
}

void DaveParachute(GameObject& Dave,
	GameObject& jet)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);
	JetPack& GameTile = dynamic_cast<JetPack&>(jet);
	gamePlayer.setJet(true);
}

void DaveKill(GameObject& Dave,
	GameObject& fireObject)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);
	gamePlayer.setsetLife(true);
	gamePlayer.setFly();

}
//------------------------------------------------
void DaveDoor(GameObject& Dave,
	GameObject& doorObject)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);

	if(gamePlayer.getTrophy())
		gamePlayer.setWinner(true);
}
//------------------------------------------------
void EnemyVsBullet(GameObject& vir,
	GameObject& bullet)
{
	Virus& virus = dynamic_cast<Virus&>(vir);
	virus.setLife(true);
		
}
void DaveTrophy(GameObject& Dave,
	GameObject& trophy)
{
	DoctorDave& dave = dynamic_cast<DoctorDave&>(Dave);

	dave.setTrophy(true);
}
void DaveGameTile(GameObject& Dave,GameObject& GameTile)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);

	float GameTileX = GameTile.getObjSprite().getGlobalBounds().left;
	float GameTileY = GameTile.getObjSprite().getGlobalBounds().top;
	if (abs(GameTileX - gamePlayer.getObjSprite().getGlobalBounds().left) < Cell_Size && 
		abs(GameTileY - gamePlayer.getObjSprite().getGlobalBounds().top) < (Cell_Size-1)
		&& ((gamePlayer.getAction()->getMove().x < 0 && GameTileX < gamePlayer.getObjSprite().getGlobalBounds().left)
			|| (gamePlayer.getAction()->getMove().x > 0 && GameTileX > gamePlayer.getObjSprite().getGlobalBounds().left))
		&& !gamePlayer.getAxe(0))
	{
		gamePlayer.getAction()->getMove().x = 0;
		gamePlayer.setAxe(0, true);
	}

	if (abs(GameTileY - gamePlayer.getObjSprite().getGlobalBounds().top) < Cell_Size &&
		abs(GameTileX - gamePlayer.getObjSprite().getGlobalBounds().left) < (Cell_Size-1)
		&& ((gamePlayer.getAction()->getMove().y < 0 && GameTileY < gamePlayer.getObjSprite().getGlobalBounds().top)
			|| (gamePlayer.getAction()->getMove().y > 0 && GameTileY > gamePlayer.getObjSprite().getGlobalBounds().top))
		&& !gamePlayer.getAxe(1))
	{
		gamePlayer.getAction()->getMove().y = 0;
		gamePlayer.getAction()->setJump(true);
		gamePlayer.setAxe(1, true);
	}

}

void GameTileDave(GameObject& Dave,
	GameObject& GameTile){	DaveGameTile(Dave, GameTile);}

void GameTileEnemy(GameObject& Enemy,GameObject& GameTile){EnemyGameTile(Enemy, GameTile);}
	
	
void AntidoteDave(GameObject& Dave,GameObject& Antidote){	DaveAntidote(Dave, Antidote);}

void TrophyDave(GameObject& Dave,GameObject& trophy){DaveTrophy(Dave, trophy);}
	
void BulletVsEnemy(GameObject& virus,GameObject& bullet){EnemyVsBullet(virus, bullet);}
	
void GameTileBullet(GameObject& Bullet,GameObject& GameTile){EnemyGameTile(Bullet, GameTile);}

void RockBullet(GameObject& bullet,GameObject& DarkTile){BulletRock(bullet, DarkTile);}

void DoorBullet(GameObject& bullet,GameObject& Door){BulletDoor(bullet, Door);}

void FireBullet(GameObject& bullet, GameObject& fire) { BulletFire(bullet, fire); }

void ParachuteDave(GameObject& Dave,GameObject& jet){DaveParachute(Dave, jet);}
	
void KillDave(GameObject& Dave,GameObject& fire){DaveKill(Dave, fire);}
	
void DoorDave(GameObject& Dave,GameObject& door){DaveDoor(Dave, door);}
	
void DaveDiamond(GameObject& Dave, GameObject&dia)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);
	gamePlayer.addScore();
}
void DiamondDave(GameObject& dia, GameObject&gamePlayer){DaveDiamond(gamePlayer, dia);}
	
void DaveCorona(GameObject& Dave,
	GameObject& enem)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);
	CoronaVirus& enemy = dynamic_cast<CoronaVirus&>(enem);

	gamePlayer.setsetLife(true);
	gamePlayer.setFly();
	enemy.setLife(true);
		
}

	

void DaveFlu(GameObject& Dave,
	GameObject& enem)
{
	DoctorDave&gamePlayer= dynamic_cast<DoctorDave&>(Dave);
	FluVirus& enemy = dynamic_cast<FluVirus&>(enem);

	gamePlayer.setsetLife(true);
	gamePlayer.setFly();
	enemy.setLife(true);
}

void DaveBulletVirus(GameObject& Dave,
	GameObject& bulletVirus)
{
	DoctorDave& gamePlayer = dynamic_cast<DoctorDave&>(Dave);
	Bullet& bullet = dynamic_cast<Bullet&>(bulletVirus);

	gamePlayer.setsetLife(true);
	gamePlayer.setFly();
	bullet.setLife(true);
}

void CoronaDave(GameObject& gamePlayer,GameObject& enemy){	

	DaveCorona(gamePlayer, enemy);
}

void FluDave(GameObject& gamePlayer, GameObject& enemy){

	DaveFlu(gamePlayer, enemy);
}

void BulletVirusDave(GameObject& gamePlayer, GameObject& bullet){

	DaveBulletVirus(gamePlayer, bullet);
}


using func = void(*)(GameObject& obj1, GameObject& obj2);
using Key = pair<type_index, type_index>;
using HitMap = map<Key, func>;

HitMap initializeCollisionMap()
{
	HitMap coll;

	coll[Key(typeid(DoctorDave), typeid(GameTile))] = &DaveGameTile;
	coll[Key(typeid(GameTile), typeid(DoctorDave))] = &GameTileDave;
	coll[Key(typeid(DoctorDave), typeid(DarkTile))] = &DaveGameTile;
	coll[Key(typeid(DarkTile), typeid(DoctorDave))] = &GameTileDave;

	coll[Key(typeid(Virus), typeid(GameTile))] = &EnemyGameTile;
	coll[Key(typeid(GameTile), typeid(Virus))] = &GameTileEnemy;
	coll[Key(typeid(Virus), typeid(DarkTile))] = &EnemyGameTile;
	coll[Key(typeid(DarkTile), typeid(Virus))] = &GameTileEnemy;

	coll[Key(typeid(DoctorDave), typeid(Antidote))] = &DaveAntidote;
	coll[Key(typeid(Antidote), typeid(DoctorDave))] = &AntidoteDave;
		
	coll[Key(typeid(DoctorDave), typeid(Trophy))] = &DaveTrophy;
	coll[Key(typeid(Trophy), typeid(DoctorDave))] = &TrophyDave;

	coll[Key(typeid(DoctorDave), typeid(JetPack))] = &DaveParachute;
	coll[Key(typeid(JetPack), typeid(DoctorDave))] = &ParachuteDave;
	coll[Key(typeid(DoctorDave), typeid(Fire))] = &DaveKill;
	coll[Key(typeid(Fire), typeid(DoctorDave))] = &KillDave;
		
	
	coll[Key(typeid(DoctorDave), typeid(CoronaVirus))] = &KillDave;
	coll[Key(typeid(CoronaVirus), typeid(DoctorDave))] = &KillDave;
	coll[Key(typeid(DoctorDave), typeid(FluVirus))] = &KillDave;
	coll[Key(typeid(FluVirus), typeid(DoctorDave))] = &KillDave;

	coll[Key(typeid(DoctorDave), typeid(Door))] = &DaveDoor;
	coll[Key(typeid(Door), typeid(DoctorDave))] = &DoorDave;

	coll[Key(typeid(Bullet), typeid(CoronaVirus))] = &BulletVsEnemy;
	coll[Key(typeid(CoronaVirus), typeid(Bullet))] = &EnemyVsBullet;
	coll[Key(typeid(FluVirus), typeid(Bullet))] = &EnemyVsBullet;
	coll[Key(typeid(Bullet), typeid(FluVirus))] = &EnemyVsBullet;

	coll[Key(typeid(DoctorDave), typeid(Diamond))] = &DaveDiamond;
	coll[Key(typeid(Diamond), typeid(DoctorDave))] = &DiamondDave;

	coll[Key(typeid(DoctorDave), typeid(CoronaVirus))] = &DaveCorona;
	coll[Key(typeid(CoronaVirus), typeid(DoctorDave))] = &CoronaDave;

	coll[Key(typeid(DoctorDave), typeid(FluVirus))] = &DaveFlu;
	coll[Key(typeid(FluVirus), typeid(DoctorDave))] = &FluDave;

	coll[Key(typeid(DoctorDave), typeid(Bullet))] = &DaveBulletVirus;
	coll[Key(typeid(Bullet), typeid(DoctorDave))] = &BulletVirusDave;

	coll[Key(typeid(Bullet), typeid(GameTile))] = &BulletGameTile;
	coll[Key(typeid(GameTile), typeid(Bullet))] = &GameTileBullet;


	coll[Key(typeid(Bullet), typeid(Door))] = &BulletDoor;
	coll[Key(typeid(Door), typeid(Bullet))] = &DoorBullet;

	coll[Key(typeid(Bullet), typeid(Fire))] = &BulletFire;
	coll[Key(typeid(Fire), typeid(Bullet))] = &FireBullet;



	coll[Key(typeid(Bullet), typeid(DarkTile))] = &BulletRock;
	coll[Key(typeid(DarkTile), typeid(Bullet))] = &RockBullet;
		
	return coll;
}

func seek(const std::type_index& class1, const std::type_index& class2)
{
	static HitMap collisionMap = initializeCollisionMap();
	auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
	if (mapEntry == collisionMap.end())
	{
		return nullptr;
	}
	return mapEntry->second;
}
 

void setCollision(GameObject& object1, GameObject& object2)
{
	auto p = seek(typeid(object1), typeid(object2));
	if (!p)	throw UnidentifiedColl();
	p(object1, object2);
}


bool checkIfCollision(const sf::FloatRect& ShapA, const sf::FloatRect& ShapB)
{
	return (sf::FloatRect{ ShapA.left - 1, ShapA.top - 2, ShapA.width - 2, ShapA.height - 2 }.intersects(sf::FloatRect
		{ ShapB.left + 1.f,ShapB.top + 2.f,ShapB.width, ShapB.height - 2 }));
};