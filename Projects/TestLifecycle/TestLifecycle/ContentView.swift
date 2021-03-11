//
//  ContentView.swift
//  TestLifecycle
//
//  Created by Mario Elsnig on 05.02.21.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView {
            List() {
                ForEach(0...30, id: \.self) { section in
                    NavigationLink(destination: EmptyView()) {
                        EmptyView()
                    }
                }
            }
            .listStyle(InsetListStyle())
            .frame(minWidth: 150, idealWidth: 150, maxWidth: 250,
                   minHeight: 400, maxHeight: .infinity)

//            StatusList(title: "", statuses: [])
        }
        .navigationTitle("HTTP Status Codes")
        .modifier(ToolbarModifier())
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
struct ToolbarModifier: ViewModifier {
    func body(content: Content) -> some View {
        content
            .toolbar {
                ToolbarItem {
                    Button(action: {
//                        NotificationCenter.default.post(name: .flipImage, object: nil)
                    } ) {
                        Image(systemName: "arrow.left.and.right.righttriangle.left.righttriangle.right")
                    }
                }

                ToolbarItem {
                    Button(action: {
//                        NotificationCenter.default.post(name: .showSamples, object: nil)
                    } ) {
                        Image(systemName: "uiwindow.split.2x1")
                    }
                }
            }
    }
}
