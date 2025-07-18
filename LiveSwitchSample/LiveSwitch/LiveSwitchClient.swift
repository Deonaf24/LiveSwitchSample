//
//  LiveSwitchClient.swift
//  LiveSwitchSample
//
//  Created by Deon Aftahi on 2025-07-17.
//

import Foundation

class LiveSwitchClient {
    private var client: FMLiveSwitchClient?

    init() {
        // Your LiveSwitch config
        let applicationId = "LiveSwitchSample"
        let sharedSecret = "your-shared-secret"
        let channelId = "your-channel-id"
        let userId = "user1"
        let deviceId = "ios-device"
        let clientId = "ios-client"

        // Generate token
        let token = FMLiveSwitchToken.generateClientRegisterToken(
            withApplicationId: applicationId,
            userId: userId,
            deviceId: deviceId,
            clientId: clientId,
            channelId: channelId,
            sharedSecret: sharedSecret
        )

        // Initialize client
        client = FMLiveSwitchClient(token: token)

        client?.onConnectSuccess({ channels in
            print("✅ Connected to LiveSwitch with \(channels?.count ?? 0) channel(s)")
        })

        client?.onConnectFailure({ client, error in
            print("❌ Connection failed: \(error?.localizedDescription ?? "Unknown error")")
        })

        client?.connect()
    }
}
