{{ $args := parseArgs 1 "" (carg "user" "target user") }}
{{$userid := ($args.Get 0) }}
{{$thumb := ("https://cdn.discordapp.com/attachments/294958600277983233/803027001589104720/image0.gif") }}
{{$warlogo := ("https://static.wikia.nocookie.net/clashofclans/images/9/97/LeagueMedal.png/revision/latest?cb=20181023140411") }}
{{$wmbot := ("https://cdn.discordapp.com/avatars/185112286308990991/27545a25d79e2547b8bfc861e58a7043.png?size=1024") }}
{{$reaction :=("https://reaction-role.com/static/favicon/favicon.png") }}

{{$war := complexMessage "content" $userid.Mention "embed" (cembed "title" (joinStr "" "Hey there! " $userid.Username ", Welcome to the war-room!")
"description" `This right here is the *war-room.* Stuck on a base? Don't worry! Post a __*screenshot*__ here and ask for help, a lot of willing volunteers would love to help you *plan* your attack.  This room is __***strictly***__ limited to war related discussions only. Need some CC for a __*war attack*__? Feel free to tag the <@&818685274430242847> &  <@&749043993672810616> roles depending on your **requirements!** __***Don't abuse***__ it.`  "color" 2938576 "thumbnail" (sdict "url" $warlogo))}}

{{$wmchannel := complexMessage "content" $userid.Mention "embed" (cembed "title" (joinStr "" "Almost there! " $userid.Username ", Welcome to the wm-bot channel!")
"description" `**You finally made it here!**, this is the __*wmbot channel*__. Here’s where you call the bases, and **log your attacks**, during war. Let’s get started by typing in __***!wm refresh***__, followed by __***!wm identify <your-ingame-name>***__. This will set you up with the bot and get you registered. Check out this *guide* for additional information and specifics- <#769244397123665960>!`  "color" 2938576 "thumbnail" (sdict "url" $wmbot))}}

{{$welcome := complexMessage "content" $userid.Mention "embed" (cembed "title" (joinStr "" "Ahoy! " $userid.Username ", Welcome on-board!")
"description" `Please change your nickname to reflect  your *in-game name* and, have a read through the __***rules***__ by clicking this [link](https://www.reddit.com/r/RedditPirates/wiki/royals).


Here're *some* of the channels that you should look out for. Make sure you follow and **read** through the *instructions* __***below***__!

> [#royals_war_room](https://discord.com/channels/258970772842872844/511738610693701634) - This right here is the *war-room.* Stuck on a base? Don't worry! Post a __*screenshot*__ here and ask for help, a lot of willing volunteers would love to help you *plan* your attack.  This room is __***strictly***__ limited to war related discussions only. Need some CC for a __*war attack*__? Feel free to tag the <@&818685274430242847> &  <@&749043993672810616> roles depending on your **requirements!** __***Don't abuse***__ it. 

> [#wmbot_royal_pirates](https://discord.com/channels/258970772842872844/749047736426299492) -  This is the __*wmbot channel*__. Here’s where you call the bases, and **log your attacks**, during war. Let’s get started by typing in __***!wm refresh***__, followed by __***!wm identify <your-ingame-name>***__. This will set you up with the bot and get you registered. Check out this *guide* for additional information and specifics- <#769244397123665960>! 

Welcome once again, get your sails up and enjoy the ocean!` "color" 26367 "thumbnail" (sdict "url" $thumb))}}

{{ $roles := (cembed "title" (joinStr "" "Don't forget to update your roles!")
"description" `Here's a list of *self-assigning* __***roles***__ available at <#786332089784074250>!

> __***Townhall Roles***__: React to the message to receive the appropriate townhall roles!

> __***Voluntary Roles***__: React to the message to receive __*voluntary support*__ roles, when *in need*, people would **tag** this role for *troops/sieges.*

> __***Permanent Super Troop Roles***__: React to receive a __*super troop role*__ that you've **boosted** which *never expires!*

> __***Temporary 3-day Super Troop Roles***__: React to receive a __*super troop role*__ that you've **boosted** which *expires* after __***3-days.***__ Make sure to react again to receive the role!` "color" 16766720 "thumbnail" (sdict "url" $reaction))}}


{{if .Message.Mentions}}
{{giveRoleID (index .Message.Mentions 0) 752705350410698772}}
{{takeRoleID (index .Message.Mentions 0) 798350031358656543}}
{{end}}

{{sendMessage 258970772842872844 $welcome}}
{{sendMessage 258970772842872844 $roles}}
{{sendMessage 258970772842872844 $war}}
{{sendMessage 258970772842872844 $wmchannel}}
{{end}}


