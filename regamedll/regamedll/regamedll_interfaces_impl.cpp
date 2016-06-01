/*
*
*    This program is free software; you can redistribute it and/or modify it
*    under the terms of the GNU General Public License as published by the
*    Free Software Foundation; either version 2 of the License, or (at
*    your option) any later version.
*
*    This program is distributed in the hope that it will be useful, but
*    WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program; if not, write to the Free Software Foundation,
*    Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
*    In addition, as a special exception, the author gives permission to
*    link the code of this program with the Half-Life Game Engine ("HL
*    Engine") and Modified Game Libraries ("MODs") developed by Valve,
*    L.L.C ("Valve").  You must obey the GNU General Public License in all
*    respects for all of the code used other than the HL Engine and MODs
*    from Valve.  If you modify this file, you may extend this exception
*    to your version of the file, but you are not obligated to do so.  If
*    you do not wish to do so, delete this exception statement from your
*    version.
*
*/

#include "precompiled.h"

void CCSEntity::FireBullets(int iShots, Vector &vecSrc, Vector &vecDirShooting, Vector &vecSpread, float flDistance, int iBulletType, int iTracerFreq, int iDamage, entvars_t *pevAttacker) {
	m_pContainingEntity->FireBullets(iShots, vecSrc, vecDirShooting, vecSpread, flDistance, iBulletType, iTracerFreq, iDamage, pevAttacker);
};

Vector CCSEntity::FireBullets3(Vector &vecSrc, Vector &vecDirShooting, float vecSpread, float flDistance, int iPenetration, int iBulletType, int iDamage, float flRangeModifier, entvars_t *pevAttacker, bool bPistol, int shared_rand) {
	return m_pContainingEntity->FireBullets3(vecSrc, vecDirShooting, vecSpread, flDistance, iPenetration, iBulletType, iDamage, flRangeModifier, pevAttacker, bPistol, shared_rand);
};

bool CCSPlayer::RemovePlayerItem(const char* pszItemName)
{
	CBasePlayer *pPlayer = BasePlayer();

	for (auto pItem : pPlayer->m_rgpPlayerItems) {
		while (pItem != nullptr)
		{
			if (FClassnameIs(pItem->pev, pszItemName))
			{
				CBasePlayerWeapon *pWeapon = static_cast<CBasePlayerWeapon *>(pItem);
				if (pWeapon->IsWeapon()) {
					pWeapon->RetireWeapon();
				}

				pPlayer->pev->weapons &= ~(1 << pItem->m_iId);
				pPlayer->RemovePlayerItem(pItem);
				pItem->Kill();
				return true;
			}

			pItem = pItem->m_pNext;
		}
	}

	return false;
}

bool CCSPlayer::IsConnected() const { return m_pContainingEntity->has_disconnected == false; }
void CCSPlayer::SetAnimation(PLAYER_ANIM playerAnim) { BasePlayer()->SetAnimation(playerAnim); }
void CCSPlayer::AddAccount(int amount, RewardType type, bool bTrackChange) { BasePlayer()->AddAccount(amount, type, bTrackChange); }
void CCSPlayer::GiveNamedItem(const char *pszName) { BasePlayer()->GiveNamedItem(pszName); }
void CCSPlayer::GiveNamedItemEx(const char *pszName) { BasePlayer()->GiveNamedItemEx(pszName); }
void CCSPlayer::GiveDefaultItems() { BasePlayer()->GiveDefaultItems(); }
void CCSPlayer::GiveShield(bool bDeploy) { BasePlayer()->GiveShield(bDeploy); }
void CCSPlayer::DropShield(bool bDeploy) { BasePlayer()->DropShield(bDeploy); }
void CCSPlayer::DropPlayerItem(const char *pszItemName) { BasePlayer()->DropPlayerItem(pszItemName); }
void CCSPlayer::RemoveShield() { BasePlayer()->RemoveShield(); }
void CCSPlayer::RemoveAllItems(bool bRemoveSuit) { BasePlayer()->RemoveAllItems(bRemoveSuit ? TRUE : FALSE); }
void CCSPlayer::SetPlayerModel(bool bHasC4) { BasePlayer()->SetPlayerModel(bHasC4 ? TRUE : FALSE); }
void CCSPlayer::SetPlayerModelEx(const char *modelName) { strncpy(m_szModel, modelName, sizeof(m_szModel) - 1); m_szModel[sizeof(m_szModel) - 1] = '\0'; };
void CCSPlayer::SetNewPlayerModel(const char *modelName) { BasePlayer()->SetNewPlayerModel(modelName); }
void CCSPlayer::ClientCommand(const char *cmd, const char *arg1, const char *arg2, const char *arg3) { BasePlayer()->ClientCommand(cmd, arg1, arg2, arg3); }
void CCSPlayer::SetProgressBarTime(int time) { BasePlayer()->SetProgressBarTime(time); }
void CCSPlayer::SetProgressBarTime2(int time, float timeElapsed) { BasePlayer()->SetProgressBarTime2(time, timeElapsed); }
edict_t *CCSPlayer::EntSelectSpawnPoint() { return BasePlayer()->EntSelectSpawnPoint(); }
void CCSPlayer::SendItemStatus() { BasePlayer()->SendItemStatus(); }
