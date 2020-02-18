import { BrowserModule } from "@angular/platform-browser";
import { NgModule } from "@angular/core";

import { AppComponent } from "./app.component";
import { BrowserAnimationsModule } from "@angular/platform-browser/animations";
import { FlexLayoutModule } from "@angular/flex-layout";
import { MatListModule } from "@angular/material/list";
import { PhotoListComponent } from "./photo-list/photo-list.component";
import { ColorListComponent } from "./color-list/color-list.component";
import { HttpClientModule } from "@angular/common/http";
import { SideBarComponent } from "./side-bar/side-bar.component";

@NgModule({
  declarations: [
    AppComponent,
    PhotoListComponent,
    ColorListComponent,
    SideBarComponent
  ],
  imports: [
    BrowserModule,
    BrowserAnimationsModule,
    FlexLayoutModule,
    MatListModule,
    HttpClientModule
  ],
  providers: [],
  bootstrap: [AppComponent, SideBarComponent]
})
export class AppModule {}