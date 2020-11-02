/**
 * SPDX-FileCopyrightText: 2017  Konstantinos Sideris <siderisk@auth.gr>
 *
 * SPDX-LicenseIdentifier: GPL-3.0-or-later
 */

#include <QByteArray>
#include <QDebug>

#include "emojimodel.h"

QVariantList EmojiModel::history() {
  return m_settings->value("Editor/emojis", QVariantList()).toList();
}

QVariantList EmojiModel::filterModel(const QString& filter) {
  QVariantList result;

  for (QVariant e : people) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }
  for (QVariant e : nature) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }
  for (QVariant e : food) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }
  for (QVariant e : activity) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }
  for (QVariant e : travel) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }
  for (QVariant e : objects) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }
  for (QVariant e : symbols) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }
  for (QVariant e : flags) {
    auto emoji = qvariant_cast<Emoji>(e);
    if (emoji.shortname.startsWith(filter)) {
      result.append(e);
    }
  }

  return result;
}

void EmojiModel::emojiUsed(QVariant modelData) {
  QVariantList list = history();

  auto it = list.begin();
  while (it != list.end()) {
    if ((*it).value<Emoji>().unicode == modelData.value<Emoji>().unicode) {
      it = list.erase(it);
    } else
      it++;
  }

  list.push_front(modelData);
  m_settings->setValue("Editor/emojis", list);

  emit historyChanged();
}

const QVariantList EmojiModel::people = {
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x80"), ":grinning:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\x81"), ":grin:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\x82"), ":joy:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa3"), ":rofl:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x83"), ":smiley:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x84"), ":smile:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x85"), ":sweat_smile:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x86"), ":laughing:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\x89"), ":wink:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x8a"), ":blush:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\x8b"), ":yum:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x8e"), ":sunglasses:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x8d"), ":heart_eyes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x98"), ":kissing_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x97"), ":kissing:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x99"), ":kissing_smiling_eyes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x9a"), ":kissing_closed_eyes:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\xba"), ":relaxed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x82"), ":slight_smile:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x97"), ":hugging:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x94"), ":thinking:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x90"), ":neutral_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x91"), ":expressionless:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb6"), ":no_mouth:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x84"), ":rolling_eyes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x8f"), ":smirk:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xa3"), ":persevere:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\xa5"),
                              ":disappointed_relieved:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xae"), ":open_mouth:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x90"), ":zipper_mouth:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xaf"), ":hushed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xaa"), ":sleepy:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xab"), ":tired_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb4"), ":sleeping:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x8c"), ":relieved:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa4\x93"), ":nerd:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x9b"), ":stuck_out_tongue:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\x9c"),
                              ":stuck_out_tongue_winking_eye:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\x9d"),
                              ":stuck_out_tongue_closed_eyes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa4"), ":drooling_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x92"), ":unamused:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x93"), ":sweat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x94"), ":pensive:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x95"), ":confused:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x83"), ":upside_down:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x91"), ":money_mouth:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb2"), ":astonished:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\xb9"), ":frowning2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x81"), ":slight_frown:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x96"), ":confounded:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x9e"), ":disappointed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x9f"), ":worried:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xa4"), ":triumph:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\xa2"), ":cry:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\xad"), ":sob:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xa6"), ":frowning:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xa7"), ":anguished:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xa8"), ":fearful:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xa9"), ":weary:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xac"), ":grimacing:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb0"), ":cold_sweat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb1"), ":scream:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb3"), ":flushed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb5"), ":dizzy_face:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\xa1"), ":rage:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xa0"), ":angry:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x87"), ":innocent:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa0"), ":cowboy:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa1"), ":clown:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa5"), ":lying_face:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x98\xb7"), ":mask:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x92"), ":thermometer_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x95"), ":head_bandage:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa2"), ":nauseated_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa7"), ":sneezing_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\x88"), ":smiling_imp:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xbf"), ":imp:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb9"), ":japanese_ogre:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xba"), ":japanese_goblin:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x80"), ":skull:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xbb"), ":ghost:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xbd"), ":alien:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x96"), ":robot:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xa9"), ":poop:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xba"), ":smiley_cat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb8"), ":smile_cat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xb9"), ":joy_cat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xbb"), ":heart_eyes_cat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xbc"), ":smirk_cat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xbd"), ":kissing_cat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x80"), ":scream_cat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xbf"), ":crying_cat_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x98\xbe"), ":pouting_cat:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xa6"), ":boy:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xa7"), ":girl:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xa8"), ":man:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xa9"), ":woman:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb4"), ":older_man:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb5"), ":older_woman:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xb6"), ":baby:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xbc"), ":angel:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xae"), ":cop:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x95\xb5"), ":spy:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x82"), ":guardsman:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb7"), ":construction_worker:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb3"), ":man_with_turban:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xb1"),
                              ":person_with_blond_hair:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x85"), ":santa:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb6"), ":mrs_claus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb8"), ":princess:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb4"), ":prince:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb0"), ":bride_with_veil:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb5"), ":man_in_tuxedo:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb0"), ":pregnant_woman:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xb2"), ":man_with_gua_pi_mao:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x8d"), ":person_frowning:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x99\x8e"),
                              ":person_with_pouting_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x85"), ":no_good:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x86"), ":ok_woman:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\x81"),
                              ":information_desk_person:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x8b"), ":raising_hand:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x99\x87"), ":bow:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xa6"), ":face_palm:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb7"), ":shrug:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x86"), ":massage:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x87"), ":haircut:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb6"), ":walking:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x83"), ":runner:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x83"), ":dancer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xba"), ":man_dancing:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xaf"), ":dancers:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xa3"), ":speaking_head:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xa4"), ":bust_in_silhouette:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xa5"), ":busts_in_silhouette:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xab"), ":couple:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xac"),
                              ":two_men_holding_hands:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xad"),
                              ":two_women_holding_hands:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x8f"), ":couplekiss:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x91"), ":couple_with_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xaa"), ":family:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xaa"), ":muscle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb3"), ":selfie:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x88"), ":point_left:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x89"), ":point_right:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x9d"), ":point_up:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x86"), ":point_up_2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x95"), ":middle_finger:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x87"), ":point_down:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\x8c"), ":v:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x9e"), ":fingers_crossed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x96"), ":vulcan:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x98"), ":metal:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x99"), ":call_me:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x90"), ":hand_splayed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\x8b"), ":raised_hand:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x8c"), ":ok_hand:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x8d"), ":thumbsup:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x8e"), ":thumbsdown:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\x8a"), ":fist:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x8a"), ":punch:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x9b"), ":left_facing_fist:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x9c"), ":right_facing_fist:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x9a"), ":raised_back_of_hand:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\x8b"), ":wave:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\x8f"), ":clap:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\x8d"), ":writing_hand:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x90"), ":open_hands:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x8c"), ":raised_hands:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x99\x8f"), ":pray:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\x9d"), ":handshake:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x85"), ":nail_care:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\x82"), ":ear:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\x83"), ":nose:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xa3"), ":footprints:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\x80"), ":eyes:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\x81"), ":eye:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x85"), ":tongue:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\x84"), ":lips:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\x8b"), ":kiss:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xa4"), ":zzz:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x93"), ":eyeglasses:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xb6"), ":dark_sunglasses:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x94"), ":necktie:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x95"), ":shirt:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x96"), ":jeans:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x97"), ":dress:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x98"), ":kimono:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x99"), ":bikini:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x9a"), ":womans_clothes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x9b"), ":purse:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x9c"), ":handbag:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x9d"), ":pouch:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x92"), ":school_satchel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x9e"), ":mans_shoe:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x9f"), ":athletic_shoe:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xa0"), ":high_heel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xa1"), ":sandal:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x91\xa2"), ":boot:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x91"), ":crown:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x92"), ":womans_hat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa9"), ":tophat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x93"), ":mortar_board:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\x91"), ":helmet_with_cross:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x84"), ":lipstick:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\x8d"), ":ring:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x82"), ":closed_umbrella:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xbc"), ":briefcase:"}),
};

const QVariantList EmojiModel::nature = {
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x88"), ":see_no_evil:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x89"), ":hear_no_evil:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x99\x8a"), ":speak_no_evil:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xa6"), ":sweat_drops:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xa8"), ":dash:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xb5"), ":monkey_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x92"), ":monkey:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x8d"), ":gorilla:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xb6"), ":dog:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x95"), ":dog2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa9"), ":poodle:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xba"), ":wolf:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa6\x8a"), ":fox:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xb1"), ":cat:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x88"), ":cat2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x81"), ":lion_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xaf"), ":tiger:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x85"), ":tiger2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x86"), ":leopard:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xb4"), ":horse:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x8e"), ":racehorse:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa6\x8c"), ":deer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x84"), ":unicorn:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xae"), ":cow:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x82"), ":ox:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x83"), ":water_buffalo:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x84"), ":cow2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xb7"), ":pig:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x96"), ":pig2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x97"), ":boar:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xbd"), ":pig_nose:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x8f"), ":ram:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x91"), ":sheep:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x90"), ":goat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xaa"), ":dromedary_camel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xab"), ":camel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x98"), ":elephant:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x8f"), ":rhino:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xad"), ":mouse:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x81"), ":mouse2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x80"), ":rat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xb9"), ":hamster:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xb0"), ":rabbit:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x87"), ":rabbit2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xbf"), ":chipmunk:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa6\x87"), ":bat:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xbb"), ":bear:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa8"), ":koala:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xbc"), ":panda_face:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xbe"), ":feet:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x83"), ":turkey:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x94"), ":chicken:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x93"), ":rooster:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa3"), ":hatching_chick:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa4"), ":baby_chick:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa5"), ":hatched_chick:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xa6"), ":bird:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa7"), ":penguin:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x95\x8a"), ":dove:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x85"), ":eagle:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa6\x86"), ":duck:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa6\x89"), ":owl:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\xb8"), ":frog:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x8a"), ":crocodile:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa2"), ":turtle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x8e"), ":lizard:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x8d"), ":snake:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xb2"), ":dragon_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x89"), ":dragon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xb3"), ":whale:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x8b"), ":whale2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xac"), ":dolphin:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x9f"), ":fish:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa0"), ":tropical_fish:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\xa1"), ":blowfish:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x88"), ":shark:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x99"), ":octopus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x9a"), ":shell:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa6\x80"), ":crab:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x90"), ":shrimp:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x91"), ":squid:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x8b"), ":butterfly:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x8c"), ":snail:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x9b"), ":bug:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x9c"), ":ant:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x90\x9d"), ":bee:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x90\x9e"), ":beetle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xb7"), ":spider:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xb8"), ":spider_web:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa6\x82"), ":scorpion:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x90"), ":bouquet:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb8"), ":cherry_blossom:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb5"), ":rosette:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb9"), ":rose:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x80"), ":wilted_rose:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xba"), ":hibiscus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xbb"), ":sunflower:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xbc"), ":blossom:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb7"), ":tulip:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb1"), ":seedling:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb2"), ":evergreen_tree:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb3"), ":deciduous_tree:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb4"), ":palm_tree:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb5"), ":cactus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xbe"), ":ear_of_rice:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\xbf"), ":herb:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x98"), ":shamrock:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x80"), ":four_leaf_clover:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x81"), ":maple_leaf:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x82"), ":fallen_leaf:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x83"), ":leaves:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x84"), ":mushroom:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb0"), ":chestnut:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x8d"), ":earth_africa:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x8e"), ":earth_americas:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x8f"), ":earth_asia:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x91"), ":new_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x92"), ":waxing_crescent_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x93"), ":first_quarter_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x94"), ":waxing_gibbous_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x95"), ":full_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x96"), ":waning_gibbous_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x97"), ":last_quarter_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x98"), ":waning_crescent_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x99"), ":crescent_moon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x9a"), ":new_moon_with_face:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\x9b"),
                              ":first_quarter_moon_with_face:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\x9c"),
                              ":last_quarter_moon_with_face:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x80"), ":sunny:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x9d"), ":full_moon_with_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x9e"), ":sun_with_face:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\xad\x90"), ":star:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x9f"), ":star2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x81"), ":cloud:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\x85"), ":partly_sunny:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\x88"), ":thunder_cloud_rain:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa4"),
                              ":white_sun_small_cloud:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa5"), ":white_sun_cloud:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa6"), ":white_sun_rain_cloud:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa7"), ":cloud_rain:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa8"), ":cloud_snow:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa9"), ":cloud_lightning:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xaa"), ":cloud_tornado:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\xab"), ":fog:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xac"), ":wind_blowing_face:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\x82"), ":umbrella2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x94"), ":umbrella:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\xa1"), ":zap:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9d\x84"), ":snowflake:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x83"), ":snowman2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\x84"), ":snowman:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x84"), ":comet:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\xa5"), ":fire:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xa7"), ":droplet:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x8a"), ":ocean:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x83"), ":jack_o_lantern:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x84"), ":christmas_tree:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\xa8"), ":sparkles:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x8b"), ":tanabata_tree:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x8d"), ":bamboo:"}),
};

const QVariantList EmojiModel::food = {
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x87"), ":grapes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x88"), ":melon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x89"), ":watermelon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x8a"), ":tangerine:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x8b"), ":lemon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x8c"), ":banana:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x8d"), ":pineapple:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x8e"), ":apple:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x8f"), ":green_apple:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\x90"), ":pear:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x91"), ":peach:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x92"), ":cherries:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x93"), ":strawberry:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa5\x9d"), ":kiwi:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x85"), ":tomato:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x91"), ":avocado:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x86"), ":eggplant:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x94"), ":potato:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x95"), ":carrot:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\xbd"), ":corn:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xb6"), ":hot_pepper:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x92"), ":cucumber:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x9c"), ":peanuts:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x9e"), ":bread:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x90"), ":croissant:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x96"), ":french_bread:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x9e"), ":pancakes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa7\x80"), ":cheese:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x96"), ":meat_on_bone:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x97"), ":poultry_leg:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x93"), ":bacon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x94"), ":hamburger:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x9f"), ":fries:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x95"), ":pizza:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xad"), ":hotdog:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\xae"), ":taco:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xaf"), ":burrito:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x99"), ":stuffed_flatbread:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa5\x9a"), ":egg:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb3"), ":cooking:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x98"), ":shallow_pan_of_food:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb2"), ":stew:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x97"), ":salad:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xbf"), ":popcorn:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb1"), ":bento:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x98"), ":rice_cracker:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x99"), ":rice_ball:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\x9a"), ":rice:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x9b"), ":curry:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x9c"), ":ramen:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\x9d"), ":spaghetti:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa0"), ":sweet_potato:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa2"), ":oden:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa3"), ":sushi:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa4"), ":fried_shrimp:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa5"), ":fish_cake:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa1"), ":dango:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa6"), ":icecream:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa7"), ":shaved_ice:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa8"), ":ice_cream:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xa9"), ":doughnut:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xaa"), ":cookie:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x82"), ":birthday:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb0"), ":cake:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xab"), ":chocolate_bar:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xac"), ":candy:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xad"), ":lollipop:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xae"), ":custard:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xaf"), ":honey_pot:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xbc"), ":baby_bottle:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa5\x9b"), ":milk:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\x95"), ":coffee:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb5"), ":tea:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb6"), ":sake:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xbe"), ":champagne:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb7"), ":wine_glass:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb8"), ":cocktail:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb9"), ":tropical_drink:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8d\xba"), ":beer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xbb"), ":beers:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x82"), ":champagne_glass:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x83"), ":tumbler_glass:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xbd"), ":fork_knife_plate:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8d\xb4"), ":fork_and_knife:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x84"), ":spoon:"}),
};

const QVariantList EmojiModel::activity = {
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\xbe"), ":space_invader:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xb4"), ":levitate:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xba"), ":fencer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x87"), ":horse_racing:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x87\xf0\x9f\x8f\xbb"),
              ":horse_racing_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x87\xf0\x9f\x8f\xbc"),
              ":horse_racing_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x87\xf0\x9f\x8f\xbd"),
              ":horse_racing_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x87\xf0\x9f\x8f\xbe"),
              ":horse_racing_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x87\xf0\x9f\x8f\xbf"),
              ":horse_racing_tone5:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb7"), ":skier:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x82"), ":snowboarder:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8c"), ":golfer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x84"), ":surfer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x84\xf0\x9f\x8f\xbb"),
              ":surfer_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x84\xf0\x9f\x8f\xbc"),
              ":surfer_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x84\xf0\x9f\x8f\xbd"),
              ":surfer_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x84\xf0\x9f\x8f\xbe"),
              ":surfer_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x84\xf0\x9f\x8f\xbf"),
              ":surfer_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa3"), ":rowboat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa3\xf0\x9f\x8f\xbb"),
              ":rowboat_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa3\xf0\x9f\x8f\xbc"),
              ":rowboat_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa3\xf0\x9f\x8f\xbd"),
              ":rowboat_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa3\xf0\x9f\x8f\xbe"),
              ":rowboat_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa3\xf0\x9f\x8f\xbf"),
              ":rowboat_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8a"), ":swimmer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8a\xf0\x9f\x8f\xbb"),
              ":swimmer_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8a\xf0\x9f\x8f\xbc"),
              ":swimmer_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8a\xf0\x9f\x8f\xbd"),
              ":swimmer_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8a\xf0\x9f\x8f\xbe"),
              ":swimmer_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8a\xf0\x9f\x8f\xbf"),
              ":swimmer_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\xb9"), ":basketball_player:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb9\xf0\x9f\x8f\xbb"),
                              ":basketball_player_tone1:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb9\xf0\x9f\x8f\xbc"),
                              ":basketball_player_tone2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb9\xf0\x9f\x8f\xbd"),
                              ":basketball_player_tone3:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb9\xf0\x9f\x8f\xbe"),
                              ":basketball_player_tone4:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb9\xf0\x9f\x8f\xbf"),
                              ":basketball_player_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8b"), ":lifter:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8b\xf0\x9f\x8f\xbb"),
              ":lifter_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8b\xf0\x9f\x8f\xbc"),
              ":lifter_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8b\xf0\x9f\x8f\xbd"),
              ":lifter_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8b\xf0\x9f\x8f\xbe"),
              ":lifter_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8b\xf0\x9f\x8f\xbf"),
              ":lifter_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb4"), ":bicyclist:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb4\xf0\x9f\x8f\xbb"),
              ":bicyclist_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb4\xf0\x9f\x8f\xbc"),
              ":bicyclist_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb4\xf0\x9f\x8f\xbd"),
              ":bicyclist_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb4\xf0\x9f\x8f\xbe"),
              ":bicyclist_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb4\xf0\x9f\x8f\xbf"),
              ":bicyclist_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb5"), ":mountain_bicyclist:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb5\xf0\x9f\x8f\xbb"),
              ":mountain_bicyclist_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb5\xf0\x9f\x8f\xbc"),
              ":mountain_bicyclist_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb5\xf0\x9f\x8f\xbd"),
              ":mountain_bicyclist_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb5\xf0\x9f\x8f\xbe"),
              ":mountain_bicyclist_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb5\xf0\x9f\x8f\xbf"),
              ":mountain_bicyclist_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb8"), ":cartwheel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb8\xf0\x9f\x8f\xbb"),
              ":cartwheel_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb8\xf0\x9f\x8f\xbc"),
              ":cartwheel_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb8\xf0\x9f\x8f\xbd"),
              ":cartwheel_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb8\xf0\x9f\x8f\xbe"),
              ":cartwheel_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb8\xf0\x9f\x8f\xbf"),
              ":cartwheel_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbc"), ":wrestlers:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbc\xf0\x9f\x8f\xbb"),
              ":wrestlers_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbc\xf0\x9f\x8f\xbc"),
              ":wrestlers_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbc\xf0\x9f\x8f\xbd"),
              ":wrestlers_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbc\xf0\x9f\x8f\xbe"),
              ":wrestlers_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbc\xf0\x9f\x8f\xbf"),
              ":wrestlers_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbd"), ":water_polo:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbd\xf0\x9f\x8f\xbb"),
              ":water_polo_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbd\xf0\x9f\x8f\xbc"),
              ":water_polo_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbd\xf0\x9f\x8f\xbd"),
              ":water_polo_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbd\xf0\x9f\x8f\xbe"),
              ":water_polo_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbd\xf0\x9f\x8f\xbf"),
              ":water_polo_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbe"), ":handball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbe\xf0\x9f\x8f\xbb"),
              ":handball_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbe\xf0\x9f\x8f\xbc"),
              ":handball_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbe\xf0\x9f\x8f\xbd"),
              ":handball_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbe\xf0\x9f\x8f\xbe"),
              ":handball_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xbe\xf0\x9f\x8f\xbf"),
              ":handball_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb9"), ":juggling:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb9\xf0\x9f\x8f\xbb"),
              ":juggling_tone1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb9\xf0\x9f\x8f\xbc"),
              ":juggling_tone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb9\xf0\x9f\x8f\xbd"),
              ":juggling_tone3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb9\xf0\x9f\x8f\xbe"),
              ":juggling_tone4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa4\xb9\xf0\x9f\x8f\xbf"),
              ":juggling_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xaa"), ":circus_tent:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xad"), ":performing_arts:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa8"), ":art:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb0"), ":slot_machine:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9b\x80"), ":bath:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x9b\x80\xf0\x9f\x8f\xbb"), ":bath_tone1:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x9b\x80\xf0\x9f\x8f\xbc"), ":bath_tone2:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x9b\x80\xf0\x9f\x8f\xbd"), ":bath_tone3:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x9b\x80\xf0\x9f\x8f\xbe"), ":bath_tone4:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x9b\x80\xf0\x9f\x8f\xbf"), ":bath_tone5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x97"), ":reminder_ribbon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x9f"), ":tickets:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xab"), ":ticket:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x96"), ":military_medal:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x86"), ":trophy:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x85"), ":medal:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x87"), ":first_place:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x88"), ":second_place:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x89"), ":third_place:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\xbd"), ":soccer:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\xbe"), ":baseball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x80"), ":basketball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x90"), ":volleyball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x88"), ":football:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x89"), ":rugby_football:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xbe"), ":tennis:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb1"), ":8ball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb3"), ":bowling:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8f"), ":cricket:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x91"), ":field_hockey:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x92"), ":hockey:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x93"), ":ping_pong:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb8"), ":badminton:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x8a"), ":boxing_glove:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\xa5\x8b"), ":martial_arts_uniform:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa5\x85"), ":goal:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8e\xaf"), ":dart:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb3"), ":golf:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\xb8"), ":ice_skate:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa3"),
                              ":fishing_pole_and_fish:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8e\xbd"),
                              ":running_shirt_with_sash:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8e\xbf"), ":ski:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xae"), ":video_game:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb2"), ":game_die:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xbc"), ":musical_score:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa4"), ":microphone:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa7"), ":headphones:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb7"), ":saxophone:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb8"), ":guitar:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb9"), ":musical_keyboard:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xba"), ":trumpet:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xbb"), ":violin:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\xa5\x81"), ":drum:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xac"), ":clapper:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb9"), ":bow_and_arrow:"}),
};

const QVariantList EmojiModel::travel = {
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8e"), ":race_car:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x8d"), ":motorcycle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xbe"), ":japan:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x94"), ":mountain_snow:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb0"), ":mountain:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x8b"), ":volcano:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xbb"), ":mount_fuji:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x95"), ":camping:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x96"), ":beach:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x9c"), ":desert:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x9d"), ":island:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8f\x9e"), ":park:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x9f"), ":stadium:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x9b"), ":classical_building:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x97"), ":construction_site:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x98"), ":homes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x99"), ":cityscape:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x9a"), ":house_abandoned:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa0"), ":house:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa1"), ":house_with_garden:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa2"), ":office:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa3"), ":post_office:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa4"), ":european_post_office:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa5"), ":hospital:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa6"), ":bank:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa8"), ":hotel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa9"), ":love_hotel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xaa"), ":convenience_store:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xab"), ":school:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xac"), ":department_store:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xad"), ":factory:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xaf"), ":japanese_castle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb0"), ":european_castle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x92"), ":wedding:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xbc"), ":tokyo_tower:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xbd"), ":statue_of_liberty:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xaa"), ":church:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x8c"), ":mosque:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x8d"), ":synagogue:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\xa9"), ":shinto_shrine:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x8b"), ":kaaba:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb2"), ":fountain:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xba"), ":tent:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x81"), ":foggy:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x83"), ":night_with_stars:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8c\x84"),
                              ":sunrise_over_mountains:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x85"), ":sunrise:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x86"), ":city_dusk:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x87"), ":city_sunset:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x89"), ":bridge_at_night:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x8c"), ":milky_way:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa0"), ":carousel_horse:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa1"), ":ferris_wheel:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa2"), ":roller_coaster:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x82"), ":steam_locomotive:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x83"), ":railway_car:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x84"), ":bullettrain_side:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x85"), ":bullettrain_front:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x86"), ":train2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x87"), ":metro:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x88"), ":light_rail:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x89"), ":station:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\x8a"), ":tram:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x9d"), ":monorail:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x9e"), ":mountain_railway:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x8b"), ":train:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\x8c"), ":bus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x8d"), ":oncoming_bus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x8e"), ":trolleybus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x90"), ":minibus:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x91"), ":ambulance:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x92"), ":fire_engine:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x93"), ":police_car:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x94"), ":oncoming_police_car:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\x95"), ":taxi:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x96"), ":oncoming_taxi:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x97"), ":red_car:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x98"), ":oncoming_automobile:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x99"), ":blue_car:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x9a"), ":truck:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x9b"), ":articulated_lorry:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x9c"), ":tractor:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb2"), ":bike:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xb4"), ":scooter:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xb5"), ":motor_scooter:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x8f"), ":busstop:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xa3"), ":motorway:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xa4"), ":railway_track:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xbd"), ":fuelpump:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa8"), ":rotating_light:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa5"), ":traffic_light:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa6"),
                              ":vertical_traffic_light:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa7"), ":construction:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\x93"), ":anchor:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb5"), ":sailboat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xb6"), ":canoe:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa4"), ":speedboat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xb3"), ":cruise_ship:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\xb4"), ":ferry:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xa5"), ":motorboat:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa2"), ":ship:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\x88"), ":airplane:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xa9"), ":airplane_small:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xab"), ":airplane_departure:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xac"), ":airplane_arriving:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xba"), ":seat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x81"), ":helicopter:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x9f"), ":suspension_railway:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa0"), ":mountain_cableway:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa1"), ":aerial_tramway:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\x80"), ":rocket:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xb0"), ":satellite_orbital:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa0"), ":stars:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x88"), ":rainbow:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x86"), ":fireworks:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x87"), ":sparkler:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x91"), ":rice_scene:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\x81"), ":checkered_flag:"}),
};

const QVariantList EmojiModel::objects = {
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\xa0"), ":skull_crossbones:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x8c"), ":love_letter:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xa3"), ":bomb:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x95\xb3"), ":hole:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x8d"), ":shopping_bags:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xbf"), ":prayer_beads:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\x8e"), ":gem:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xaa"), ":knife:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xba"), ":amphora:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x97\xba"), ":map:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x88"), ":barber:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\xbc"), ":frame_photo:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x8e"), ":bellhop:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xaa"), ":door:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9b\x8c"),
                              ":sleeping_accommodation:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9b\x8f"), ":bed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x8b"), ":couch:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xbd"), ":toilet:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xbf"), ":shower:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x81"), ":bathtub:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8c\x9b"), ":hourglass:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xb3"), ":hourglass_flowing_sand:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x8c\x9a"), ":watch:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xb0"), ":alarm_clock:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xb1"), ":stopwatch:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x8f\xb2"), ":timer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xb0"), ":clock:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\xa1"), ":thermometer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\xb1"), ":beach_umbrella:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x88"), ":balloon:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8e\x89"), ":tada:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x8a"), ":confetti_ball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x8e"), ":dolls:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x8f"), ":flags:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x90"), ":wind_chime:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x80"), ":ribbon:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8e\x81"), ":gift:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xb9"), ":joystick:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xaf"), ":postal_horn:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x99"), ":microphone2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x9a"), ":level_slider:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x9b"), ":control_knobs:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xbb"), ":radio:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb1"), ":iphone:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb2"), ":calling:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\x8e"), ":telephone:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x9e"), ":telephone_receiver:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x9f"), ":pager:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\xa0"), ":fax:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x8b"), ":battery:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x8c"), ":electric_plug:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xbb"), ":computer:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\xa5"), ":desktop:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\xa8"), ":printer:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x8c\xa8"), ":keyboard:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\xb1"), ":mouse_three_button:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\xb2"), ":trackball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xbd"), ":minidisc:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xbe"), ":floppy_disk:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xbf"), ":cd:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\x80"), ":dvd:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa5"), ":movie_camera:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x9e"), ":film_frames:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xbd"), ":projector:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\xba"), ":tv:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb7"), ":camera:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb8"), ":camera_with_flash:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb9"), ":video_camera:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\xbc"), ":vhs:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x8d"), ":mag:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x8e"), ":mag_right:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xac"), ":microscope:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xad"), ":telescope:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa1"), ":satellite:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xaf"), ":candle:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xa1"), ":bulb:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xa6"), ":flashlight:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xae"), ":izakaya_lantern:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\x94"),
                              ":notebook_with_decorative_cover:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x95"), ":closed_book:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\x96"), ":book:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x97"), ":green_book:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x98"), ":blue_book:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x99"), ":orange_book:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x9a"), ":books:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x93"), ":notebook:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x92"), ":ledger:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x83"), ":page_with_curl:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x9c"), ":scroll:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x84"), ":page_facing_up:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb0"), ":newspaper:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x9e"), ":newspaper2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x91"), ":bookmark_tabs:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x96"), ":bookmark:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb7"), ":label:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb0"), ":moneybag:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xb4"), ":yen:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb5"), ":dollar:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xb6"), ":euro:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb7"), ":pound:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb8"), ":money_with_wings:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb3"), ":credit_card:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\x89"), ":envelope:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa7"), ":e-mail:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa8"), ":incoming_envelope:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa9"), ":envelope_with_arrow:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa4"), ":outbox_tray:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa5"), ":inbox_tray:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa6"), ":package:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xab"), ":mailbox:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xaa"), ":mailbox_closed:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xac"), ":mailbox_with_mail:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xad"), ":mailbox_with_no_mail:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xae"), ":postbox:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xb3"), ":ballot_box:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\x8f"), ":pencil2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\x92"), ":black_nib:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x8b"), ":pen_fountain:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x8a"), ":pen_ballpoint:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x8c"), ":paintbrush:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x8d"), ":crayon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x9d"), ":pencil:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x81"), ":file_folder:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x82"), ":open_file_folder:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x82"), ":dividers:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\x85"), ":date:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x86"), ":calendar:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x92"), ":notepad_spiral:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x93"), ":calendar_spiral:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x87"), ":card_index:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\x88"),
                              ":chart_with_upwards_trend:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\x89"),
                              ":chart_with_downwards_trend:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x8a"), ":bar_chart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x8b"), ":clipboard:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x8c"), ":pushpin:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x8d"), ":round_pushpin:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x8e"), ":paperclip:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\x87"), ":paperclips:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x8f"), ":straight_ruler:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x90"), ":triangular_ruler:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\x82"), ":scissors:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x83"), ":card_box:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x84"), ":file_cabinet:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x91"), ":wastebasket:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x92"), ":lock:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x93"), ":unlock:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x8f"), ":lock_with_ink_pen:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x90"), ":closed_lock_with_key:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x91"), ":key:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x97\x9d"), ":key2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xa8"), ":hammer:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\x8f"), ":pick:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9a\x92"), ":hammer_pick:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xa0"), ":tools:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xa1"), ":dagger:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9a\x94"), ":crossed_swords:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\xab"), ":gun:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\xa1"), ":shield:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xa7"), ":wrench:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xa9"), ":nut_and_bolt:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\x99"), ":gear:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\x9c"), ":compression:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\x97"), ":alembic:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\x96"), ":scales:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x97"), ":link:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\x93"), ":chains:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x89"), ":syringe:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\x8a"), ":pill:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xac"), ":smoking:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\xb0"), ":coffin:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\xb1"), ":urn:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xbf"), ":moyai:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9b\xa2"), ":oil:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xae"), ":crystal_ball:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x92"), ":shopping_cart:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xa9"),
                              ":triangular_flag_on_post:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\x8c"), ":crossed_flags:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb4"), ":flag_black:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb3"), ":flag_white:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8f\xb3\xf0\x9f\x8c\x88"),
              ":rainbow_flag:"}),
};

const QVariantList EmojiModel::symbols = {
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x91\x81\xf0\x9f\x97\xa8"),
              ":eye_in_speech_bubble:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x98"), ":cupid:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9d\xa4"), ":heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x93"), ":heartbeat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x94"), ":broken_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x95"), ":two_hearts:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x96"), ":sparkling_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x97"), ":heartpulse:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x99"), ":blue_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x9a"), ":green_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x9b"), ":yellow_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x9c"), ":purple_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x96\xa4"), ":black_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x9d"), ":gift_heart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x9e"), ":revolving_hearts:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\x9f"), ":heart_decoration:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9d\xa3"), ":heart_exclamation:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xa2"), ":anger:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xa5"), ":boom:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xab"), ":dizzy:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xac"), ":speech_balloon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xa8"), ":speech_left:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x97\xaf"), ":anger_right:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xad"), ":thought_balloon:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xae"), ":white_flower:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x90"), ":globe_with_meridians:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x99\xa8"), ":hotsprings:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x91"), ":octagonal_sign:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x9b"), ":clock12:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa7"), ":clock1230:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x90"), ":clock1:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x9c"), ":clock130:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x91"), ":clock2:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x9d"), ":clock230:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x92"), ":clock3:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x9e"), ":clock330:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x93"), ":clock4:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x9f"), ":clock430:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x94"), ":clock5:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa0"), ":clock530:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x95"), ":clock6:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa1"), ":clock630:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x96"), ":clock7:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa2"), ":clock730:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x97"), ":clock8:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa3"), ":clock830:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x98"), ":clock9:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa4"), ":clock930:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x99"), ":clock10:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa5"), ":clock1030:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x9a"), ":clock11:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\xa6"), ":clock1130:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8c\x80"), ":cyclone:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\xa0"), ":spades:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\xa5"), ":hearts:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\xa6"), ":diamonds:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\xa3"), ":clubs:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x83\x8f"), ":black_joker:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x80\x84"), ":mahjong:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb4"), ":flower_playing_cards:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x87"), ":mute:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x88"), ":speaker:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x89"), ":sound:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x8a"), ":loud_sound:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xa2"), ":loudspeaker:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x93\xa3"), ":mega:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x94"), ":bell:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x95"), ":no_bell:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb5"), ":musical_note:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xb6"), ":notes:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb9"), ":chart:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb1"), ":currency_exchange:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x92\xb2"), ":heavy_dollar_sign:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x8f\xa7"), ":atm:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xae"),
                              ":put_litter_in_its_place:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb0"), ":potable_water:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x99\xbf"), ":wheelchair:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb9"), ":mens:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xba"), ":womens:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xbb"), ":restroom:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xbc"), ":baby_symbol:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x9a\xbe"), ":wc:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x82"), ":passport_control:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x83"), ":customs:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x84"), ":baggage_claim:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x85"), ":left_luggage:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\xa0"), ":warning:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb8"), ":children_crossing:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9b\x94"), ":no_entry:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xab"), ":no_entry_sign:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb3"), ":no_bicycles:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xad"), ":no_smoking:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xaf"), ":do_not_litter:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb1"), ":non-potable_water:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9a\xb7"), ":no_pedestrians:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb5"), ":no_mobile_phones:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x9e"), ":underage:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\xa2"), ":radioactive:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\xa3"), ":biohazard:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\xac\x86"), ":arrow_up:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x86\x97"), ":arrow_upper_right:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9e\xa1"), ":arrow_right:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x86\x98"), ":arrow_lower_right:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\xac\x87"), ":arrow_down:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x86\x99"), ":arrow_lower_left:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\xac\x85"), ":arrow_left:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x86\x96"), ":arrow_upper_left:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x86\x95"), ":arrow_up_down:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x86\x94"), ":left_right_arrow:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x86\xa9"),
                              ":leftwards_arrow_with_hook:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x86\xaa"), ":arrow_right_hook:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\xa4\xb4"), ":arrow_heading_up:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\xa4\xb5"), ":arrow_heading_down:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x83"), ":arrows_clockwise:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x84"),
                              ":arrows_counterclockwise:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x99"), ":back:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x9a"), ":end:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x9b"), ":on:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x9c"), ":soon:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x9d"), ":top:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x9b\x90"), ":place_of_worship:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9a\x9b"), ":atom:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x89"), ":om_symbol:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\xa1"), ":star_of_david:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\xb8"), ":wheel_of_dharma:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\xaf"), ":yin_yang:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9c\x9d"), ":cross:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\xa6"), ":orthodox_cross:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\xaa"), ":star_and_crescent:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x98\xae"), ":peace:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x95\x8e"), ":menorah:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xaf"), ":six_pointed_star:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x88"), ":aries:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x89"), ":taurus:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x8a"), ":gemini:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x8b"), ":cancer:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x8c"), ":leo:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x8d"), ":virgo:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x8e"), ":libra:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x8f"), ":scorpius:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x99\x90"), ":sagittarius:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x99\x91"), ":capricorn:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x92"), ":aquarius:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\x93"), ":pisces:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9b\x8e"), ":ophiuchus:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\x80"),
                              ":twisted_rightwards_arrows:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x81"), ":repeat:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x82"), ":repeat_one:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x96\xb6"), ":arrow_forward:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xa9"), ":fast_forward:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xad"), ":track_next:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xaf"), ":play_pause:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x97\x80"), ":arrow_backward:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x8f\xaa"), ":rewind:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xae"), ":track_previous:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xbc"), ":arrow_up_small:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xab"), ":arrow_double_up:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xbd"), ":arrow_down_small:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xac"), ":arrow_double_down:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xb8"), ":pause_button:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xb9"), ":stop_button:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x8f\xba"), ":record_button:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x8f\x8f"), ":eject:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x8e\xa6"), ":cinema:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x85"), ":low_brightness:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x86"), ":high_brightness:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb6"), ":signal_strength:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb3"), ":vibration_mode:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\xb4"), ":mobile_phone_off:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x99\xbb"), ":recycle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x93\x9b"), ":name_badge:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9a\x9c"), ":fleur-de-lis:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb0"), ":beginner:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb1"), ":trident:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\xad\x95"), ":o:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\x85"), ":white_check_mark:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x98\x91"), ":ballot_box_with_check:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\x94"), ":heavy_check_mark:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\x96"), ":heavy_multiplication_x:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9d\x8c"), ":x:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9d\x8e"),
                              ":negative_squared_cross_mark:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9e\x95"), ":heavy_plus_sign:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9e\x96"), ":heavy_minus_sign:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9e\x97"), ":heavy_division_sign:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9e\xb0"), ":curly_loop:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9e\xbf"), ":loop:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe3\x80\xbd"), ":part_alternation_mark:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\xb3"), ":eight_spoked_asterisk:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9c\xb4"), ":eight_pointed_black_star:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9d\x87"), ":sparkle:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x80\xbc"), ":bangbang:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x81\x89"), ":interrobang:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x9d\x93"), ":question:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9d\x94"), ":grey_question:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9d\x95"), ":grey_exclamation:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9d\x97"), ":exclamation:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe3\x80\xb0"), ":wavy_dash:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xc2\xa9"), ":copyright:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xc2\xae"), ":registered:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x84\xa2"), ":tm:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("#\xe2\x83\xa3"), ":hash:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("*\xe2\x83\xa3"), ":asterisk:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("0\xe2\x83\xa3"), ":zero:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("1\xe2\x83\xa3"), ":one:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("2\xe2\x83\xa3"), ":two:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("3\xe2\x83\xa3"), ":three:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("4\xe2\x83\xa3"), ":four:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("5\xe2\x83\xa3"), ":five:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("6\xe2\x83\xa3"), ":six:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("7\xe2\x83\xa3"), ":seven:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("8\xe2\x83\xa3"), ":eight:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("9\xe2\x83\xa3"), ":nine:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x9f"), ":keycap_ten:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xaf"), ":100:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xa0"), ":capital_abcd:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\xa1"), ":abcd:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\xa2"), ":1234:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xa3"), ":symbols:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\xa4"), ":abc:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x85\xb0"), ":a:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x8e"), ":ab:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x85\xb1"), ":b:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x91"), ":cl:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x92"), ":cool:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x93"), ":free:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x84\xb9"), ":information_source:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x94"), ":id:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x93\x82"), ":m:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x95"), ":new:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x96"), ":ng:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x85\xbe"), ":o2:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x97"), ":ok:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x85\xbf"), ":parking:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x98"), ":sos:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x99"), ":up:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x86\x9a"), ":vs:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x88\x81"), ":koko:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x88\x82"), ":sa:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb7"), ":u6708:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb6"), ":u6709:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xaf"), ":u6307:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x89\x90"), ":ideograph_advantage:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb9"), ":u5272:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\x9a"), ":u7121:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb2"), ":u7981:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x89\x91"), ":accept:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb8"), ":u7533:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb4"), ":u5408:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb3"), ":u7a7a:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe3\x8a\x97"), ":congratulations:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe3\x8a\x99"), ":secret:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xba"), ":u55b6:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x88\xb5"), ":u6e80:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x96\xaa"), ":black_small_square:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x96\xab"), ":white_small_square:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x97\xbb"), ":white_medium_square:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x97\xbc"), ":black_medium_square:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x97\xbd"),
                              ":white_medium_small_square:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xe2\x97\xbe"),
                              ":black_medium_small_square:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\xac\x9b"), ":black_large_square:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\xac\x9c"), ":white_large_square:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb6"), ":large_orange_diamond:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb7"), ":large_blue_diamond:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb8"), ":small_orange_diamond:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb9"), ":small_blue_diamond:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xba"), ":small_red_triangle:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x94\xbb"),
                              ":small_red_triangle_down:"}),
    QVariant::fromValue(Emoji{QString::fromUtf8("\xf0\x9f\x92\xa0"),
                              ":diamond_shape_with_a_dot_inside:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\x98"), ":radio_button:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb2"), ":black_square_button:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb3"), ":white_square_button:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9a\xaa"), ":white_circle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xe2\x9a\xab"), ":black_circle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb4"), ":red_circle:"}),
    QVariant::fromValue(
        Emoji{QString::fromUtf8("\xf0\x9f\x94\xb5"), ":blue_circle:"}),
};

const QVariantList EmojiModel::flags = {
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xa8"), ":flag_ac:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xa9"), ":flag_ad:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xaa"), ":flag_ae:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xab"), ":flag_af:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xac"), ":flag_ag:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xae"), ":flag_ai:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xb1"), ":flag_al:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xb2"), ":flag_am:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xb4"), ":flag_ao:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xb6"), ":flag_aq:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xb7"), ":flag_ar:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xb8"), ":flag_as:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xb9"), ":flag_at:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xba"), ":flag_au:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xbc"), ":flag_aw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xbd"), ":flag_ax:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa6\xf0\x9f\x87\xbf"), ":flag_az:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xa6"), ":flag_ba:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xa7"), ":flag_bb:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xa9"), ":flag_bd:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xaa"), ":flag_be:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xab"), ":flag_bf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xac"), ":flag_bg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xad"), ":flag_bh:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xae"), ":flag_bi:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xaf"), ":flag_bj:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb1"), ":flag_bl:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb2"), ":flag_bm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb3"), ":flag_bn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb4"), ":flag_bo:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb6"), ":flag_bq:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb7"), ":flag_br:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb8"), ":flag_bs:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xb9"), ":flag_bt:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xbb"), ":flag_bv:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xbc"), ":flag_bw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xbe"), ":flag_by:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa7\xf0\x9f\x87\xbf"), ":flag_bz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xa6"), ":flag_ca:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xa8"), ":flag_cc:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xa9"), ":flag_cd:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xab"), ":flag_cf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xac"), ":flag_cg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xad"), ":flag_ch:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xae"), ":flag_ci:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xb0"), ":flag_ck:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xb1"), ":flag_cl:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xb2"), ":flag_cm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xb3"), ":flag_cn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xb4"), ":flag_co:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xb5"), ":flag_cp:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xb7"), ":flag_cr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xba"), ":flag_cu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xbb"), ":flag_cv:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xbc"), ":flag_cw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xbd"), ":flag_cx:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xbe"), ":flag_cy:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa8\xf0\x9f\x87\xbf"), ":flag_cz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa9\xf0\x9f\x87\xaa"), ":flag_de:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa9\xf0\x9f\x87\xac"), ":flag_dg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa9\xf0\x9f\x87\xaf"), ":flag_dj:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa9\xf0\x9f\x87\xb0"), ":flag_dk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa9\xf0\x9f\x87\xb2"), ":flag_dm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa9\xf0\x9f\x87\xb4"), ":flag_do:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xa9\xf0\x9f\x87\xbf"), ":flag_dz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xa6"), ":flag_ea:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xa8"), ":flag_ec:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xaa"), ":flag_ee:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xac"), ":flag_eg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xad"), ":flag_eh:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xb7"), ":flag_er:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xb8"), ":flag_es:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xb9"), ":flag_et:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaa\xf0\x9f\x87\xba"), ":flag_eu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xab\xf0\x9f\x87\xae"), ":flag_fi:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xab\xf0\x9f\x87\xaf"), ":flag_fj:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xab\xf0\x9f\x87\xb0"), ":flag_fk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xab\xf0\x9f\x87\xb2"), ":flag_fm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xab\xf0\x9f\x87\xb4"), ":flag_fo:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xab\xf0\x9f\x87\xb7"), ":flag_fr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xa6"), ":flag_ga:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xa7"), ":flag_gb:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xa9"), ":flag_gd:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xaa"), ":flag_ge:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xab"), ":flag_gf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xac"), ":flag_gg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xad"), ":flag_gh:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xae"), ":flag_gi:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb1"), ":flag_gl:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb2"), ":flag_gm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb3"), ":flag_gn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb5"), ":flag_gp:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb6"), ":flag_gq:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb7"), ":flag_gr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb8"), ":flag_gs:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xb9"), ":flag_gt:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xba"), ":flag_gu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xbc"), ":flag_gw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xac\xf0\x9f\x87\xbe"), ":flag_gy:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xad\xf0\x9f\x87\xb0"), ":flag_hk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xad\xf0\x9f\x87\xb2"), ":flag_hm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xad\xf0\x9f\x87\xb3"), ":flag_hn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xad\xf0\x9f\x87\xb7"), ":flag_hr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xad\xf0\x9f\x87\xb9"), ":flag_ht:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xad\xf0\x9f\x87\xba"), ":flag_hu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xa8"), ":flag_ic:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xa9"), ":flag_id:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xaa"), ":flag_ie:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb1"), ":flag_il:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb2"), ":flag_im:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb3"), ":flag_in:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb4"), ":flag_io:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb6"), ":flag_iq:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb7"), ":flag_ir:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb8"), ":flag_is:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xae\xf0\x9f\x87\xb9"), ":flag_it:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaf\xf0\x9f\x87\xaa"), ":flag_je:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaf\xf0\x9f\x87\xb2"), ":flag_jm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaf\xf0\x9f\x87\xb4"), ":flag_jo:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xaf\xf0\x9f\x87\xb5"), ":flag_jp:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xaa"), ":flag_ke:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xac"), ":flag_kg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xad"), ":flag_kh:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xae"), ":flag_ki:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xb2"), ":flag_km:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xb3"), ":flag_kn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xb5"), ":flag_kp:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xb7"), ":flag_kr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xbc"), ":flag_kw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xbe"), ":flag_ky:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb0\xf0\x9f\x87\xbf"), ":flag_kz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xa6"), ":flag_la:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xa7"), ":flag_lb:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xa8"), ":flag_lc:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xae"), ":flag_li:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xb0"), ":flag_lk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xb7"), ":flag_lr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xb8"), ":flag_ls:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xb9"), ":flag_lt:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xba"), ":flag_lu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xbb"), ":flag_lv:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb1\xf0\x9f\x87\xbe"), ":flag_ly:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xa6"), ":flag_ma:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xa8"), ":flag_mc:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xa9"), ":flag_md:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xaa"), ":flag_me:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xab"), ":flag_mf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xac"), ":flag_mg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xad"), ":flag_mh:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb0"), ":flag_mk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb1"), ":flag_ml:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb2"), ":flag_mm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb3"), ":flag_mn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb4"), ":flag_mo:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb5"), ":flag_mp:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb6"), ":flag_mq:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb7"), ":flag_mr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb8"), ":flag_ms:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xb9"), ":flag_mt:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xba"), ":flag_mu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xbb"), ":flag_mv:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xbc"), ":flag_mw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xbd"), ":flag_mx:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xbe"), ":flag_my:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb2\xf0\x9f\x87\xbf"), ":flag_mz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xa6"), ":flag_na:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xa8"), ":flag_nc:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xaa"), ":flag_ne:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xab"), ":flag_nf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xac"), ":flag_ng:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xae"), ":flag_ni:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xb1"), ":flag_nl:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xb4"), ":flag_no:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xb5"), ":flag_np:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xb7"), ":flag_nr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xba"), ":flag_nu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb3\xf0\x9f\x87\xbf"), ":flag_nz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb4\xf0\x9f\x87\xb2"), ":flag_om:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xa6"), ":flag_pa:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xaa"), ":flag_pe:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xab"), ":flag_pf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xac"), ":flag_pg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xad"), ":flag_ph:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xb0"), ":flag_pk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xb1"), ":flag_pl:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xb2"), ":flag_pm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xb3"), ":flag_pn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xb7"), ":flag_pr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xb8"), ":flag_ps:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xb9"), ":flag_pt:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xbc"), ":flag_pw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb5\xf0\x9f\x87\xbe"), ":flag_py:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb6\xf0\x9f\x87\xa6"), ":flag_qa:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb7\xf0\x9f\x87\xaa"), ":flag_re:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb7\xf0\x9f\x87\xb4"), ":flag_ro:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb7\xf0\x9f\x87\xb8"), ":flag_rs:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb7\xf0\x9f\x87\xba"), ":flag_ru:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb7\xf0\x9f\x87\xbc"), ":flag_rw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xa6"), ":flag_sa:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xa7"), ":flag_sb:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xa8"), ":flag_sc:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xa9"), ":flag_sd:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xaa"), ":flag_se:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xac"), ":flag_sg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xad"), ":flag_sh:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xae"), ":flag_si:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xaf"), ":flag_sj:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb0"), ":flag_sk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb1"), ":flag_sl:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb2"), ":flag_sm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb3"), ":flag_sn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb4"), ":flag_so:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb7"), ":flag_sr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb8"), ":flag_ss:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xb9"), ":flag_st:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xbb"), ":flag_sv:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xbd"), ":flag_sx:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xbe"), ":flag_sy:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb8\xf0\x9f\x87\xbf"), ":flag_sz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xa6"), ":flag_ta:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xa8"), ":flag_tc:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xa9"), ":flag_td:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xab"), ":flag_tf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xac"), ":flag_tg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xad"), ":flag_th:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xaf"), ":flag_tj:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xb0"), ":flag_tk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xb1"), ":flag_tl:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xb2"), ":flag_tm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xb3"), ":flag_tn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xb4"), ":flag_to:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xb7"), ":flag_tr:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xb9"), ":flag_tt:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xbb"), ":flag_tv:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xbc"), ":flag_tw:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xb9\xf0\x9f\x87\xbf"), ":flag_tz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xba\xf0\x9f\x87\xa6"), ":flag_ua:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xba\xf0\x9f\x87\xac"), ":flag_ug:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xba\xf0\x9f\x87\xb2"), ":flag_um:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xba\xf0\x9f\x87\xb8"), ":flag_us:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xba\xf0\x9f\x87\xbe"), ":flag_uy:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xba\xf0\x9f\x87\xbf"), ":flag_uz:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbb\xf0\x9f\x87\xa6"), ":flag_va:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbb\xf0\x9f\x87\xa8"), ":flag_vc:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbb\xf0\x9f\x87\xaa"), ":flag_ve:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbb\xf0\x9f\x87\xac"), ":flag_vg:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbb\xf0\x9f\x87\xae"), ":flag_vi:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbb\xf0\x9f\x87\xb3"), ":flag_vn:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbb\xf0\x9f\x87\xba"), ":flag_vu:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbc\xf0\x9f\x87\xab"), ":flag_wf:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbc\xf0\x9f\x87\xb8"), ":flag_ws:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbd\xf0\x9f\x87\xb0"), ":flag_xk:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbe\xf0\x9f\x87\xaa"), ":flag_ye:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbe\xf0\x9f\x87\xb9"), ":flag_yt:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbf\xf0\x9f\x87\xa6"), ":flag_za:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbf\xf0\x9f\x87\xb2"), ":flag_zm:"}),
    QVariant::fromValue(Emoji{
        QString::fromUtf8("\xf0\x9f\x87\xbf\xf0\x9f\x87\xbc"), ":flag_zw:"}),
};
