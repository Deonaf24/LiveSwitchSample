//
//  ContentView.swift
//  LiveSwitchSample
//
//  Created by Deon Aftahi on 2025-07-17.
//  Modified by Codex.
//

import SwiftUI
import RealityKit
import RealityKitContent

/// Dashboard style view for HoloXR Health Connect
struct ContentView: View {
    @State private var selectedMenu: String = "Home"

    private let darkBlue = Color(red: 20/255, green: 27/255, blue: 45/255)

    var body: some View {
        HStack(spacing: 0) {
            sidebar
            Divider().hidden()
            mainContent
        }
        .padding()
        .background(darkBlue)
        .overlay(
            RoundedRectangle(cornerRadius: 20)
                .stroke(Color.orange, lineWidth: 4)
        )
    }

    // MARK: - Sidebar
    private var sidebar: some View {
        VStack(alignment: .leading, spacing: 24) {
            // Logo and title
            HStack(spacing: 8) {
                Image(systemName: "cross.case.fill")
                    .resizable()
                    .scaledToFit()
                    .frame(width: 36, height: 36)
                    .foregroundColor(.white)
                VStack(alignment: .leading, spacing: 2) {
                    HStack(spacing: 0) {
                        Text("Holo")
                        Text("XR")
                            .foregroundStyle(Color.orange)
                    }
                    .font(.headline)
                    .foregroundStyle(Color.white)

                    Text("Health Connect")
                        .font(.subheadline)
                        .foregroundColor(.white)
                }
            }
            .padding(.bottom, 16)

            sidebarButton(title: "Home")
            sidebarButton(title: "Sessions")
            sidebarButton(title: "About")
            sidebarButton(title: "Quit")

            Spacer()
        }
        .padding()
        .frame(maxWidth: 200)
        .background(darkBlue.opacity(0.8))
        .clipShape(RoundedRectangle(cornerRadius: 20))
    }

    private func sidebarButton(title: String) -> some View {
        Button(action: { selectedMenu = title }) {
            Text(title)
                .frame(maxWidth: .infinity, alignment: .leading)
                .padding()
                .foregroundColor(selectedMenu == title ? darkBlue : .white)
                .background(selectedMenu == title ? Color.white : Color.clear)
                .clipShape(RoundedRectangle(cornerRadius: 12))
                .overlay(
                    RoundedRectangle(cornerRadius: 12)
                        .stroke(selectedMenu == title ? Color.orange : Color.clear, lineWidth: 2)
                )
        }
    }

    // MARK: - Main Content
    private var mainContent: some View {
        VStack(alignment: .leading, spacing: 24) {
            VStack(alignment: .leading, spacing: 4) {
                Text("Dr. Kosar Khwaja")
                    .font(.title)
                    .bold()
                    .foregroundColor(.white)
                Text("Airmedic")
                    .font(.subheadline)
                    .foregroundColor(.white.opacity(0.8))
            }

            Text("Upcoming Sessions")
                .font(.headline)
                .foregroundColor(.white)

            sessionCard(title: "Puvirnituq Evac — June 4", subtitle: "Invited By Airmedic Command")
            sessionCard(title: "Team Meeting — June 6", subtitle: "Invited By Louis-Philippe Loiselle Fortier")

            Spacer()
        }
        .padding()
    }

    private func sessionCard(title: String, subtitle: String) -> some View {
        HStack {
            VStack(alignment: .leading, spacing: 4) {
                Text(title)
                    .font(.headline)
                    .foregroundColor(.white)
                Text(subtitle)
                    .font(.subheadline)
                    .foregroundColor(.white.opacity(0.7))
            }
            Spacer()
            Button("Join") {}
                .font(.headline)
                .padding(.vertical, 8)
                .padding(.horizontal, 16)
                .background(Color.orange)
                .foregroundColor(.white)
                .clipShape(RoundedRectangle(cornerRadius: 12))
        }
        .padding()
        .background(darkBlue.opacity(0.6))
        .clipShape(RoundedRectangle(cornerRadius: 16))
    }
}

#Preview(windowStyle: .automatic) {
    ContentView()
        .environment(AppModel())
}
